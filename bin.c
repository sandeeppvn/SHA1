#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char string[10];
char res[32];
char sum[33];
unsigned char hexstr[8]="\0";
void HEXA(char* binstr)
{
	unsigned int hexnum;
	unsigned char four[4];
	int i, j;

	for(i = 0;i < 8;++i)
	{
		hexnum = 0;
		strncpy(four, binstr + (i * 4), 4);
		for(j = 0;j < 4;++j)
			hexnum += (four[j] - '0') << (3 - j);
		sprintf(hexstr + i, "%X", hexnum);
	}
	printf("%s", hexstr);
}

char* LR(char *a,int shift)
{
	int b = a[0];
	int i=0;
	int j;

	
	for(j=0;j<shift;j++)
	{
		for(i=1;i<32;i++)
		{
			a[i-1]=a[i];
		}
		a[31]=b;
	}
	return a;

}
char* ADD(char *p,char *p1)
{
	int i;	
	int max=strlen(p)>strlen(p1)? strlen(p) : strlen(p1);
	char temp[max];
	char temp1[max];
	if(strlen(p)>strlen(p1))
	{
		for(i=0;i<(strlen(p)-strlen(p1));i++)
			temp[i]='0';
		for(i=(strlen(p)-strlen(p1));i<strlen(p);i++)
			temp[i]=p1[i];
		for(i=0;i<strlen(p);i++)
			temp1[i]=p[i];
	}
	else
	{
		for(i=0;i<(strlen(p1)-strlen(p1));i++)
			temp[i]='0';
		for(i=(strlen(p1)-strlen(p));i<strlen(p1);i++)
			temp[i]=p[i];
		for(i=0;i<strlen(p1);i++)
			temp1[i]=p1[i];
	}
	int carry=0,t1,t2,add=0;
	char v= '0';
	int val=(int)v;
	for(i=strlen(temp)-1;i>=0;i--)
	{
		t1=(int)temp[i]-val;
		t2=(int)temp1[i]-val;
		add=t1+t2+carry;
		if(add==0)
		{
			carry=0;
			sum[strlen(temp)-i-1]='0';;
		}
		else if(add==1)
		{
			carry=0;
			sum[strlen(temp)-i-1]='1';
		}
		else if(add==2)
		{
			carry=1;
			sum[strlen(temp)-i-1]='0';
		}
		else if(add==3)
		{
			carry=1;
			sum[strlen(temp)-i-1]='1';
		}
	}
	if(strlen(sum)>32)
		return sum;
	else
	{
		for(i=sizeof(sum)-1;i>0;i--)
			sum[i]=sum[i-1];
		sum[0]='0';
		return sum;
	}
		
	
}

char* Truncate(char *p,char *p1)
{
	int i;	
	int max=strlen(p)>strlen(p1)? strlen(p) : strlen(p1);
	char temp[max];
	char temp1[max];
	if(strlen(p)>strlen(p1))
	{
		for(i=0;i<(strlen(p)-strlen(p1));i++)
			temp[i]='0';
		for(i=(strlen(p)-strlen(p1));i<strlen(p);i++)
			temp[i]=p1[i];
		for(i=0;i<strlen(p);i++)
			temp1[i]=p[i];
	}
	else
	{
		for(i=0;i<(strlen(p1)-strlen(p1));i++)
			temp[i]='0';
		for(i=(strlen(p1)-strlen(p));i<strlen(p1);i++)
			temp[i]=p[i];
		for(i=0;i<strlen(p1);i++)
			temp1[i]=p1[i];
	}
	int carry=0,t1,t2,add=0;
	char v= '0';
	int val=(int)v;
	for(i=strlen(temp)-1;i>=0;i--)
	{
		t1=(int)temp[i]-val;
		t2=(int)temp1[i]-val;
		add=t1+t2+carry;
		if(add==0)
		{
			carry=0;
			sum[strlen(temp)-i-1]='0';;
		}
		else if(add==1)
		{
			carry=0;
			sum[strlen(temp)-i-1]='1';
		}
		else if(add==2)
		{
			carry=1;
			sum[strlen(temp)-i-1]='0';
		}
		else if(add==3)
		{
			carry=1;
			sum[strlen(temp)-i-1]='1';
		}
	}
	if(strlen(sum)<32)
	{
		for(i=sizeof(sum)-1;i>0;i--)
			sum[i]=sum[i-1];
		sum[0]='0';
	}
	
	for(i=max;i>=(max-32);i--)
		res[i]=sum[i];
	return res;	
	
}
char* AND(char *p,char *p1)
{
	int i;
	for(i=0;i<32;i++)
	{
		if(p[i]==p1[i]&&(p[i]=='1'))
		    res[i]='1';
		else
		    res[i]='0';
	}
	return res;
}
char* OR(char *p,char *p1)
{
	int i;
	for(i=0;i<32;i++)
	{
		if(p[i]=='1'||p1[i]=='1')
			res[i]='1';
		else
			res[i]='0';
	}
	return res;
}
char* XOR(char *p,char *p1)
{
	int i;
	for(i=0;i<32;i++)
	{
		if(p[i]=='1'&&p1[i]=='0')
			res[i]='1';
		else if(p[i]=='0'&&p1[i]=='1')
			res[i]='1';
		else
			res[i]='0';
	}
	return res;
}
char* NOT(char *p)
{
	int i;
	for(i=0;i<32;i++)
	{
		if(p[i]=='1')
			res[i]='0';
		else
			res[i]='1';
	}
	return res;
}

char* fn(long int t,int pad)
{
	long int decimalNumber,remainder,quotient;
	int binaryNumber[100],i=1,j;
	decimalNumber=t;
	quotient = decimalNumber;
	while(quotient!=0)
	{
		binaryNumber[i++]= quotient % 2;
		quotient = quotient / 2;
	}
	int test = pad-i;
	int k[pad];
	for(j=0;j<test+1;j++)
		k[j] = 0;
	int v;
	int l=0;
	for(v = i -1 ;v> 0;v--)
	{
		l++;
		k[test+l] = binaryNumber[v];
	}
	for(j=0;j<pad;j++)
	{
		if(k[j]==1)
			string[j]= 1+'0';
		else
			string[j] = 0+'0';
	}
	return string;
}

void main()
{
	char *ip;
	ip=(char*)malloc(10000000*sizeof(char));
	scanf("%[^\\0]",ip);
/*	while(check==0)
	{
		char t=scanf("%c",ip+l);
		if(t=='~')
			check=1;
		l++;
	}
*/
	int len=strlen(ip);
	int i;
	char *bin;
	bin=(char*)malloc(len*8*sizeof(char));
	*bin='\0';
	for(i=0;i<len-1;i++)
	{
		int t=(int)(*(ip+i));
		bin=strcat(bin,fn(t,8));		
	}
	//printf("%s",ip);
	free(ip);
	int sz=strlen(bin);
	int no_of_blocks= sz/512;
	int t=0;
	//printf("%d\n",sz);
	if(sz%512 > 448)
	{
		no_of_blocks+=1;
		t=len%512;
		bin=strcat(bin,"1");
		t++;
		while(t<=512)
		{
			bin=strcat(bin,"0");
			t++;
		}
		t=1;
		while(t<448)
		{
			bin=strcat(bin,"0");
			t++;
		}
	}
	else if(sz%512 < 448)
	{
		t=len%512;
		bin=strcat(bin,"1");
		t++;
		while(t<448)
		{
			bin=strcat(bin,"0");
			t++;
		}
	}
	if(no_of_blocks==0)
		no_of_blocks++;
	bin=strcat(bin,fn(sz,64));
	//printf("%s\n\n%s\n\n%d\n\n\n",ip,bin,no_of_blocks);
	
	int j,x;
	
	char w[80][32];
	//printf("%s\n",bin);
	
	char h0[32] = "01100111010001010010001100000001";
	char h1[32] = "11101111110011011010101110001001";
	char h2[32] = "10011000101110101101110011111110";
	char h3[32] = "00010000001100100101010001110110";
	char h4[32] = "11000011110100101110000111110000";

	char a[32],b[32],c[32],d[32],e[32],f[50];
	char k[50]="\0";
	char temp[100]="\0";
	strncpy(a, h0, sizeof(a));
	a[sizeof(a) - 1] = '\0';
	strncpy(b, h1, sizeof(b));
	b[sizeof(b) - 1] = '\0';
	strncpy(c, h2, sizeof(c));
	c[sizeof(c) - 1] = '\0';
	strncpy(d, h3, sizeof(d));
	d[sizeof(d) - 1] = '\0';
	strncpy(e, h4, sizeof(e));
	e[sizeof(e) - 1] = '\0';
	/*a=h0;
	b=h1;
	c=h2;
	d=h3;
	e=h4;*/
	
	//printf("%d",no_of_blocks);
	for(i=1;i<=no_of_blocks;i++)
	{
		
		for(j=0;j<512;j++)
		{
			if(j>=0 && j<32)
				w[0][j%32]=bin[(i-1)*512 + j];
			if(j>=32 && j<64)
				w[1][j%32]=bin[(i-1)*512 + j];
			if(j>=64 && j<96)
				w[2][j%32]=bin[(i-1)*512 + j];
			if(j>=96 && j<128)
				w[3][j%32]=bin[(i-1)*512 + j];
			if(j>=128 && j<160)
				w[4][j%32]=bin[(i-1)*512 + j];
			if(j>=160 && j<192)
				w[5][j%32]=bin[(i-1)*512 + j];
			if(j>=192 && j<224)
				w[6][j%32]=bin[(i-1)*512 + j];
			if(j>=224 && j<256)
				w[7][j%32]=bin[(i-1)*512 + j];
			if(j>=256 && j<288)
				w[8][j%32]=bin[(i-1)*512 + j];
			if(j>=288 && j<320)
				w[9][j%32]=bin[(i-1)*512 + j];
			if(j>=320 && j<352)
				w[10][j%32]=bin[(i-1)*512 + j];
			if(j>=352 && j<384)
				w[11][j%32]=bin[(i-1)*512 + j];
			if(j>=384 && j<416)
				w[12][j%32]=bin[(i-1)*512 + j];
			if(j>=416 && j<448)
				w[13][j%32]=bin[(i-1)*512 + j];
			if(j>=448 && j<480)
				w[14][j%32]=bin[(i-1)*512 + j];
			if(j>=480 && j<512)
				w[15][j%32]=bin[(i-1)*512 + j];
			
		}
		//printf("%s",bin);	
		
		for(j=16;j<80;j++)
		{
			strncpy(w[j], LR( XOR( XOR( XOR(w[j-3],w[j-8]) ,w[j-14]) , w[j-16]) , 1 ) , sizeof(w[j]));
			w[j][sizeof(w[j]) - 1] = '\0';
			//w[j] = LR( XOR( XOR( XOR(w[j-3],w[j-8]) ,w[j-14]) , w[j-16]) , 1 )
		}
		//printf("%s",w[79]);
		for(j=0;j<80;j++)
		{
			
			if(j>=0 && j<20)
			{
				strncpy(f, OR(AND(b , c) , AND( NOT(b) , d)), sizeof(f));
				f[sizeof(f) - 1] = '\0';
				//f= OR(AND(b , c) , AND( NOT(b) , d));
				strncpy(k, "01011010100000100111100110011001" , sizeof(k));
				k[sizeof(k) - 1] = '\0';
			}
			else if(j>=20 && j<40)
			{
				strncpy(f, XOR( XOR(b,c) , d) , sizeof(f));
				f[sizeof(f) - 1] = '\0';
				strncpy(k, "01101110110110011110101110100001" , sizeof(k));
				k[sizeof(k) - 1] = '\0';
				//f= XOR( XOR(b,c) , d);
				//k=
			}
			else if(j>=40 && j<60)
			{
				strncpy(f, OR( OR( AND(b,c) , AND(b,d) ) , AND(c,d) ) , sizeof(f));
				f[sizeof(f) - 1] = '\0';
				strncpy(k, "10001111000110111011110011011100" , sizeof(k));		
				k[sizeof(k) - 1] = '\0';		
				//f= OR( OR( AND(b,c) , AND(b,d) ) , AND(c,d) );
				//k=
			}
			else if(j>=60 && j<80)
			{
				strncpy(f, XOR( XOR(b,c) , d) , sizeof(f));
				f[sizeof(f) - 1] = '\0';
				strncpy(k, "11001010011000101100000111010110" , sizeof(k));		
				k[sizeof(k) - 1] = '\0';		
				//f= XOR( XOR(b,c) , d);
				//k=
			}
			//printf("%s\t%s\n",f,k);
			strncpy(temp, ADD(ADD(ADD(ADD(LR(a,5),f),e),k),w[j]) , sizeof(temp));
			temp[sizeof(temp) - 1] = '\0';
			//temp=ADD( ADD( ADD( ADD( LR(a,5) , f) , e ) , k) , w[j]);
			//printf("%s\n",a);
			//printf("%s\n",temp);
			strncpy(e, d, sizeof(e));
			e[sizeof(e) - 1] = '\0';
			strncpy(d, c, sizeof(d));
			d[sizeof(d) - 1] = '\0';
			strncpy(c, b, sizeof(c));
			c[sizeof(c) - 1] = '\0';
			strncpy(b, a, sizeof(b));
			b[sizeof(b) - 1] = '\0';
			strncpy(a, temp, sizeof(a));
			a[sizeof(a) - 1] = '\0';
			/*e=d;
			d=c;
			c=LR(b,30);
			b=a;
			a=temp;*/
			
			
		}
		//printf("%s\t%s\t%s\n",h3,h1,h2);
		strncpy(h0, a, sizeof(h0));
		h0[sizeof(h0) - 1] = '\0';
		strncpy(h1, b, sizeof(h1));
		h1[sizeof(h1) - 1] = '\0';
		strncpy(h2, c, sizeof(h2));
		h2[sizeof(h2) - 1] = '\0';
		strncpy(h3, d, sizeof(h3));
		h3[sizeof(h3) - 1] = '\0';
		strncpy(h4, e, sizeof(h4));
		h4[sizeof(h4) - 1] = '\0';
		
		/*for(i=strlen(h1);i<32;i++)
		{
			strncpy(h0, strcat(h0,"0"), sizeof(h0));
			h0[sizeof(h0) - 1] = '\0';
		}
		for(i=strlen(h1);i<32;i++)
		{
			strncpy(h1, strcat(h1,"0"), sizeof(h1));
			h1[sizeof(h1) - 1] = '\0';
		}
		for(i=strlen(h2);i<32;i++)
		{
			strncpy(h2, strcat(h2,"0"), sizeof(h2));
			h2[sizeof(h2) - 1] = '\0';
		}
		for(i=strlen(h3);i<32;i++)
		{
			strncpy(h3, strcat(h3,"0"), sizeof(h3));
			h3[sizeof(h3) - 1] = '\0';
		}
		for(i=strlen(h4);i<32;i++)
		{
			strncpy(h4, strcat(h4,"0"), sizeof(h4));
			h4[sizeof(h4) - 1] = '\0';
		}*/

		//printf("%s\n%s\n%s\n%s\n%s\n",h0,h1,h2,h3,h4);
/*
		h0=Truncate(h0,a);
		h1=Truncate(h1,b);
		h2=Truncate(h2,c);
		h3=Truncate(h3,d);
		h4=Truncate(h4,e);	*/
					
	}
	printf("\n");
	HEXA(h0);HEXA(h1);HEXA(h2);HEXA(h3);HEXA(h4);
	printf("\n");
	
	
}
















