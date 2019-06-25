#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int i=0;
	//float x1,x2,b1,b2,w1,w2,w3,w4,w5,w6,w7,w8,t1,t2,lr,galat;
	char jawab;
	
	float x1=0.05,
		  x2=0.10,
		  b1=0.35,
		  b2=0.60,
		  w1=0.15,
		  w2=0.20,
		  w3=0.25,
		  w4=0.30,
		  w5=0.40,
		  w6=0.45,
		  w7=0.50,
		  w8=0.55,
		  t1=0.01,
		  t2=0.99,
		  lr=0.5,
		  galat=0.28;
	cout<<"w1  = "<<w1<<endl;
	cout<<"w2  = "<<w2<<endl;
	cout<<"w3  = "<<w3<<endl;
	cout<<"w4  = "<<w4<<endl;
	cout<<"w5  = "<<w5<<endl;
	cout<<"w6  = "<<w6<<endl;
	cout<<"w7  = "<<w7<<endl;
	cout<<"w8  = "<<w8<<endl;
	

	/*
	cout<<"Masukkan input x1 = ";
	cin>>x1;
	cout<<"Masukkan input x2 = ";
	cin>>x2;
	cout<<"Masukkan bobot b1 = ";
	cin>>b1;
	cout<<"Masukkan bobot b2 = ";
	cin>>b2;
	cout<<"Masukkan initial wight w1 = ";
	cin>>w1;
	cout<<"Masukkan initial wight w2 = ";
	cin>>w2;
	cout<<"Masukkan initial wight w3 = ";
	cin>>w3;
	cout<<"Masukkan initial wight w4 = ";
	cin>>w4;
	cout<<"Masukkan initial wight w5 = ";
	cin>>w5;
	cout<<"Masukkan initial wight w6 = ";
	cin>>w6;
	cout<<"Masukkan initial wight w7 = ";
	cin>>w7;
	cout<<"Masukkan initial wight w8 = ";
	cin>>w8;
	cout<<"Masukkan nilai target t1 = ";
	cin>>t1;
	cout<<"Masukkan nilai target t2 = ";
	cin>>t2;
	cout<<"Masukkan learning rate   = ";
	cin>>lr;
	cout<<"Masukkan Error minimum   = ";
	cin>>galat;
	*/
	
	cout<<"=================================="<<endl<<endl;
	
	loop:
	
	cout<<"Forward Pass"<<endl;
	
	float h1,outh1,h2,outh2,y1,outy1,y2,outy2;
	
	h1=(x1*w1)+(x2*w2)+b1;
	outh1=1/(1+exp(-h1));
	
	h2=(x1*w3)+(x2*w4)+b1;
	outh2=1/(1+exp(-h2));
	
	y1=(outh1*w5)+(outh2*w6)+b2;
	outy1=1/(1+exp(-y1));
	
	y2=(outh1*w7)+(outh2*w8)+b2;
	outy2=1/(1+exp(-y2));
	
	cout<<" h1     = "<<h1<<endl;
	cout<<" out h1 = "<<outh1<<endl;
	cout<<" h2     = "<<h2<<endl;
	cout<<" out h2 = "<<outh2<<endl;
	cout<<" y1     = "<<y1<<endl;
	cout<<" out y1 = "<<outy1<<endl;
	cout<<" y2     = "<<y2<<endl;
	cout<<" out y2 = "<<outy2<<endl;
	
	cout<<"=================================="<<endl<<endl;
	
	cout<<"Total Error"<<endl;
	
	float Etot,E1,E2;
	
	E1=0.5*pow((t1-outy1),2);
	E2=0.5*pow((t2-outy2),2);
	Etot=E1+E2;
	
	cout<<" E1     = "<<E1<<endl;
	cout<<" E2     = "<<E2<<endl;
	cout<<" Etot   = "<<Etot<<endl;
	
	cout<<"=================================="<<endl<<endl;
	
	cout<<"Back Propagation"<<endl;
	
	//UPDATE W5
	
	float dE1perdw5,dE1perdouty1,douty1perdy1,dy1perdw5;	

	//langkah 1
	dE1perdouty1=outy1-t1;
	//langkah 2
	douty1perdy1=outy1*(1-outy1);
	//langkah 3
	dy1perdw5=outh1;
	//hasil dE1 / dw5
	dE1perdw5=dE1perdouty1*douty1perdy1*dy1perdw5;
	
	cout<<" dE1 / douty1  = "<<dE1perdouty1<<endl;
	cout<<" douty1 / dy1  = "<<douty1perdy1<<endl;
	cout<<" dy1 / dw5     = "<<dy1perdw5<<endl;
	cout<<" dE1 / dw5     = "<<dE1perdw5<<endl<<endl;
	
	//UPDATE W6
	
	float dE1perdw6,dy1perdw6;
	
	//langkah 1
	dE1perdouty1=outy1-t1;
	//langkah 2
	douty1perdy1=outy1*(1-outy1);
	//langkah 3
	dy1perdw6=outh2;
	//hasil dE1 / dw6
	dE1perdw6=dE1perdouty1*douty1perdy1*dy1perdw6;
	
	cout<<" dE1 / douty1  = "<<dE1perdouty1<<endl;
	cout<<" douty1 / dy1  = "<<douty1perdy1<<endl;
	cout<<" dy1 / dw6     = "<<dy1perdw6<<endl;
	cout<<" dE1 / dw6     = "<<dE1perdw6<<endl<<endl;
	
	//UPDATE W7
	
	float dE2perdw7,dE2perdouty2,douty2perdy2,dy2perdw7;
	
	//langkah 1
	dE2perdouty2=outy2-t2;
	//langkah 2
	douty2perdy2=outy2*(1-outy2);
	//langkah 3
	dy2perdw7=outh1;
	//hasil dE2 / dw7
	dE2perdw7=dE2perdouty2*douty2perdy2*dy2perdw7;
	
	cout<<" dE2 / douty2  = "<<dE2perdouty2<<endl;
	cout<<" douty2 / dy2  = "<<douty2perdy2<<endl;
	cout<<" dy2 / dw7     = "<<dy2perdw7<<endl;
	cout<<" dE2 / dw7     = "<<dE2perdw7<<endl<<endl;
	
	//UPDATE W8
	
	float dE2perdw8,dy2perdw8;
	
	//langkah 1
	dE2perdouty2=outy2-t2;
	//langkah 2
	douty2perdy2=outy2*(1-outy2);
	//langkah 3
	dy2perdw8=outh2;
	//hasil dE2 / dw8
	dE2perdw8=dE2perdouty2*douty2perdy2*dy2perdw8;
	
	cout<<" dE2 / douty2  = "<<dE2perdouty2<<endl;
	cout<<" douty2 / dy2  = "<<douty2perdy2<<endl;
	cout<<" dy2 / dw8     = "<<dy2perdw8<<endl;
	cout<<" dE2 / dw8     = "<<dE2perdw8<<endl<<endl;
	
	//UPDATE W1
	
	float dEtotperdw1,dEtotperdouth1,douth1perdh1,dh1perdw1;
	
	//Langkah 1
	float dE1perdouth1,dE2perdouth2;	
		
		//Langkah 1.1
		float dE1perdy1,dy1perdouth1;

		dy1perdouth1=w5;
		dE1perdy1=dE1perdouty1*douty1perdy1;
		dE1perdouth1=dE1perdy1*dy1perdouth1;
		
		//langkah 1.2
		float dE2perdy2,dy2perdouth2;
		
		dy2perdouth2=w8;
		dE2perdy2=dE2perdouty2*douty2perdy2;
		dE2perdouth2=dE2perdy2*dy2perdouth2;
	
	dEtotperdouth1=dE1perdouth1+dE2perdouth2;
	
	//Langkah 2
	douth1perdh1=outh1*(1-outh1);
	
	//Langkah 3	
	dh1perdw1=x1;
	
	//hasil dEtot / dw1
	dEtotperdw1=dEtotperdouth1*douth1perdh1*dh1perdw1;
	
	cout<<" dEtot / douth1  = "<<dEtotperdouth1<<endl;
	cout<<" douth1 / dh1    = "<<douth1perdh1<<endl;
	cout<<" dh1 / dw1       = "<<dh1perdw1<<endl;
	cout<<" dEtot / dw1     = "<<dEtotperdw1<<endl<<endl;
	
	//UPDATE W2
	
	float dEtotperdw2,dh1perdw2;
	
	//Langkah 1
		
		//Langkah 1.1
		dE1perdy1=dE1perdouty1*douty1perdy1;
		dE1perdouth1=dE1perdy1*dy1perdouth1;
		
		//langkah 1.2
		dE2perdy2=dE2perdouty2*douty2perdy2;
		dE2perdouth2=dE2perdy2*dy2perdouth2;
	
	dEtotperdouth1=dE1perdouth1+dE2perdouth2;
	
	//Langkah 2
	douth1perdh1=outh1*(1-outh1);
	
	//Langkah 3	
	dh1perdw2=x2;
	
	//hasil dEtot / dw1
	dEtotperdw2=dEtotperdouth1*douth1perdh1*dh1perdw2;
	
	cout<<" dEtot / douth1  = "<<dEtotperdouth1<<endl;
	cout<<" douth1 / dh1    = "<<douth1perdh1<<endl;
	cout<<" dh1 / dw2       = "<<dh1perdw2<<endl;
	cout<<" dEtot / dw2     = "<<dEtotperdw2<<endl<<endl;
	
	//UPDATE W3
	
	float dEtotperdw3,dEtotperdouth2,douth2perdh2,dh2perdw3;
	
	//Langkah 1
	float dE1perdouth2,dE2perdouth1;	
		
		//Langkah 1.1
		float dy1perdouth2;

		dy1perdouth2=w6;
		dE1perdy1=dE1perdouty1*douty1perdy1;
		dE1perdouth2=dE1perdy1*dy1perdouth2;
		
		//langkah 1.2
		float dy2perdouth1;
		
		dy2perdouth1=w7;
		dE2perdy2=dE2perdouty2*douty2perdy2;
		dE2perdouth1=dE2perdy2*dy2perdouth1;
	
	dEtotperdouth2=dE1perdouth2+dE2perdouth1;
	
	//Langkah 2 
	douth2perdh2=outh2*(1-outh2);
	
	//Langkah 3	
	dh2perdw3=x1;
	
	//hasil dEtot / dw3
	dEtotperdw3=dEtotperdouth2*douth2perdh2*dh2perdw3;
	
	cout<<" dEtot / douth2  = "<<dEtotperdouth2<<endl;
	cout<<" douth2 / dh2    = "<<douth2perdh2<<endl;
	cout<<" dh2 / dw3       = "<<dh2perdw3<<endl;
	cout<<" dEtot / dw3     = "<<dEtotperdw3<<endl<<endl;

	//UPDATE W4
	
	float dEtotperdw4,dh2perdw4;
	
	//Langkah 1	
		
		//Langkah 1.1
		dE1perdy1=dE1perdouty1*douty1perdy1;
		dE1perdouth2=dE1perdy1*dy1perdouth2;
		
		//langkah 1.2
		dE2perdy2=dE2perdouty2*douty2perdy2;
		dE2perdouth1=dE2perdy2*dy2perdouth1;
	
	dEtotperdouth2=dE1perdouth2+dE2perdouth1;
	
	//Langkah 2 
	douth2perdh2=outh2*(1-outh2);
	
	//Langkah 3	
	dh2perdw4=x2;
	
	//hasil dEtot / dw3
	dEtotperdw4=dEtotperdouth2*douth2perdh2*dh2perdw4;
	
	cout<<" dEtot / douth2  = "<<dEtotperdouth2<<endl;
	cout<<" douth2 / dh2    = "<<douth2perdh2<<endl;
	cout<<" dh2 / dw4       = "<<dh2perdw4<<endl;
	cout<<" dEtot / dw4     = "<<dEtotperdw4<<endl<<endl;

	cout<<"=================================="<<endl<<endl;

	cout<<"Updating Weight"<<endl;
	
	w5=w5-(lr*dE1perdw5); 
	w6=w6-(lr*dE1perdw6);
	w7=w7-(lr*dE2perdw7);
	w8=w8-(lr*dE2perdw8);
	w1=w1-(lr*dEtotperdw1);
	w2=w2-(lr*dEtotperdw2);
	w3=w3-(lr*dEtotperdw3);
	w4=w4-(lr*dEtotperdw4);
	
	cout<<" w1["<<i<<"] = "<<w1<<endl;
	cout<<" w2["<<i<<"] = "<<w2<<endl;
	cout<<" w3["<<i<<"] = "<<w3<<endl;
	cout<<" w4["<<i<<"] = "<<w4<<endl;
	cout<<" w5["<<i<<"] = "<<w5<<endl;
	cout<<" w6["<<i<<"] = "<<w6<<endl;
	cout<<" w7["<<i<<"] = "<<w7<<endl;
	cout<<" w8["<<i<<"] = "<<w8<<endl<<endl;
	
	cout<<" Error       = "<<Etot<<endl<<endl;
	i+=1;
	
	if(Etot<galat){goto end;}
	
	cout<<"Apakah anda ingin melihat hasil w selanjutnya ? (Y/n)";
	cin>>jawab;
	
	if (jawab=='Y'|| jawab=='y'){goto loop;}
	
	end:
	
	cout<<"Selesai";
}
