#include<iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int get_double_digits(double num)
{
  int digits = 0;//counter
  long num2 = num;//cast to long int
  while(num2>0)//count no of digits before floating point
    {
      digits++;
      num2 = num2/10;
    }


  return digits ;
}

//=====================================================
int main()
//=====================================================
{
  double scn = 19014569;
  int sscn[12]={0,0,0,0,0,0,0,0,0,0,0,0};
  int count = get_double_digits(scn);
  int prevDig = 0;
  int prevNum = 0;
  for( int i = count; i > 0 ; i--)
    {
      sscn[i] = scn / pow(10,i-1) - prevNum;
      prevDig = ( 10 * sscn [i]) ;
      prevNum = prevNum*10+prevDig ;
      cout << "Element\t"<<i<<" is\t"<<sscn[i]<<endl;
    }
  //==============================================================
  //modify sscn
  sscn[7] = sscn[7] +9;
  sscn[0] = sscn[0] -9;
  cout<< "modify the 7th indux \t" << sscn[7] << endl;
  cout<< "modify the 7th indux \t" << sscn[0] << endl;
  //=============================================================
  float msscn=0;
  float sum=0;
  for (int x = 0; x < count; x++)
    {
      sum = sum+sscn[x];
    }

  msscn = sum/count;
  cout<< " mean is : \t "<< msscn << endl;


  //==============================================================

  float msscn1[count];

  for(int j=0 ; j< count; j++ )
    {
      msscn1[j]= sscn[j]-msscn;

      cout << "the new new mean after subtract the mean \t"<<  msscn1[j] <<endl;

    }
  //==============================================================

  float sc[24 + count ] ;
  for (int i = 0 ; i<24 + count ; i++) {

      if(i >11 && i <= count+11)
        sc[i] = msscn1[i-12] ;
      else sc[i] =0 ;

      cout<< "the extended array with 12 zero \t"<< i+1 <<"\t is\t"<< sc[i] << endl;
    }
  //=======================================================================
  double sum_xy = 0 ;
  double cs [32];
  for( int  j=0 ; j <32; j++)
    {
      cs [j] = 0 ;
    }

  for( int  i=0 ; i <32; i++)
    {
      sum_xy = 0 ; // reset counter
      for (int k =0 ; k< 8 ; k++)
        {
          if(k+i <32)sum_xy = sum_xy +  msscn1[k] * sc[k+i];
          cs[i] = sum_xy ;
          }// end of K
       cout<<"cs ["<<i+1<<"]= "<< cs[i] << endl;
    } // end of i

}
