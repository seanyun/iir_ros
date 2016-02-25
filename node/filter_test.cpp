#include "iir/iir.h"
#include <iostream>

using namespace std;

int main()
{

	const int order = 5;
	Iir::Butterworth::LowPass<order> f;
	const float samplingrate = 100; // Hz
	const float cutoff_frequency = 10; // Hz
	f.setup (order, samplingrate, cutoff_frequency);
	f.reset ();

	for(int i=0;i<100;i++)
	{
		float a=0;
		if (i%5==0) a = 1;
		float b = f.filter(a);
		cout << b << " ";
	}
	cout << endl;


	// bandstop filter
	// here the "direct form I" is chosen for the number crunching
	Iir::Butterworth::BandStop<order,Iir::DirectFormI> bs;
	const float center_frequency = 10;
	const float frequency_width = 2;
	bs.setup (order, samplingrate, center_frequency, frequency_width);
	bs.reset ();

	for(int i=0;i<100;i++)
	{
		float a=0;
		if (i%5==0) a = 1;
		float b = bs.filter(a);
		cout << b << " ";
	}
	cout<<endl;


  return 0;

}
