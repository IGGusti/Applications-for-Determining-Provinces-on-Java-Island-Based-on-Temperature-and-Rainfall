# Example of kNN implemented from Scratch in Python

import csv
import random
import math
import matplotlib.pyplot as plt
import operator

def load_data_Set(filename, split, training_Set=[] , test_Set=[]):
	with open(filename, 'rb') as csvfile:
		baris = csv.reader(csvfile)
		data_Set = list(baris)
		for x in range(len(data_Set)-1):
			for y in range(4):
	 			data_Set[x][y] = float(data_Set[x][y])
			if random.random() < split:
				training_Set.append(data_Set[x])
			else:
				test_Set.append(data_Set[x])


def euclidean_Distance(baris_test_Set, baris_training_Set, kolom_test_Set):
	jarak = 0
	for x in range(kolom_test_Set):
		jarak += pow((baris_test_Set[x] - baris_training_Set[x]), 2)
	return math.sqrt(jarak)

def get_data_sebanyak_k(training_Set, baris_test_Set, k):
	hasil_jarak = []
	kolom_test_Set = len(baris_test_Set)-1
	for x in range(len(training_Set)):
		dist = euclidean_Distance(baris_test_Set, training_Set[x], kolom_test_Set)
		hasil_jarak.append((training_Set[x], dist))
	hasil_jarak.sort(key=operator.itemgetter(1))
	ambil_sesuai_k = []
	for x in range(k):
		ambil_sesuai_k.append(hasil_jarak[x][0])
	return ambil_sesuai_k

def get_jawaban(ambil_sesuai_k):
	classVotes = {}
	for x in range(len(ambil_sesuai_k)):
		label = ambil_sesuai_k[x][-1]
		if label in classVotes:
			classVotes[label] += 1
		else:
			classVotes[label] = 1
	sortedVotes = sorted(classVotes.iteritems(), key=operator.itemgetter(1), reverse=True)
	return sortedVotes[0][0]

def get_akurasi(test_Set, prediksi):
	sama = 0
	for x in range(len(test_Set)):
		if test_Set[x][-1] == prediksi[x]:
			sama += 1
	return (sama/float(len(test_Set))) * 100.0
	
def main():
	#Menghitung pengujian k1, k2, ..., k10 sebanyak 10 kali
	pengujian = range(1,21)
	hasil_uji = []
	for x in pengujian:
		split = 0.9
		k_range = range(1,21)
		hasil_akurasi = []
		print '~ Pengujian ke-' + str(x)
		for k in k_range:
			training_Set=[]
			test_Set=[]
			load_data_Set('suhu.data', split, training_Set, test_Set)
			#print '  - K         = ' + str(k)
			#print '  - Train set = ' + repr(len(training_Set))
			#print '  - Test set  = ' + repr(len(test_Set))
			prediksi=[]
			for y in range(len(test_Set)):
				ambil_sesuai_k = get_data_sebanyak_k(training_Set, test_Set[y], k)
				hasil_akhir_label = get_jawaban(ambil_sesuai_k)
				prediksi.append(hasil_akhir_label)
				#print('    > Predicted = ' + repr(hasil_akhir_label) + ',	Actual = ' + repr(test_Set[y][-1]))
			akurasi = get_akurasi(test_Set, prediksi)
			#print('    # Akurasi   = ' + repr(akurasi) + ' %')
			#print ''
			hasil_akurasi.append(akurasi)
		hasil_uji.append(hasil_akurasi)
	print ''
	print 'Kesimpulan Keakuratan Hasil Uji'
	for x in range(len(hasil_uji)):
		print ' - Ke-' + str(x+1) + ' : ' + repr(hasil_uji[x])
	
	print ''
	print 'Rata-rata Keakuratan Hasil Uji'
	rata = []
	for x in range(len(hasil_uji[0])):
		lama=0
		i=0
		for y in range(len(hasil_uji)):
			z=hasil_uji[y][x]
			lama=lama+z
			i=i+1
		rata.append(lama/i)
		print ' - K = ' + str(x+1) + ' : ' + repr(rata[x]) + ' %'
	plt.plot(k_range, rata)
	plt.xlabel('K')
	plt.ylabel('Nilai Keakuratan K')
	plt.show()
main()