#include <cmath>
#include <iostream> 

int main() 
{
	static const int N = 10;
	double arr[N] = {0.4, 3.2, 4.6, 4.1, 6.7, 8.1, 0.1, 5.5, 9.7, 6.2};
	double massimo = arr[0];
	double minimo = arr[0];
	double s=0;
	double s1=0;
	double sq;
	int i;
	for (i=0; i<N; i++) 
	{
		s += arr[i];
		massimo = std::max(massimo, arr[i]);
		minimo = std::min(minimo, arr[i]);
	}
	double media = s/N;
	for (int i=0; i<N; i++) 
	{
		sq = std::pow(arr[i]-media,2);
		s1 += sq;
	}
	double dev_st = std::sqrt(s1/N);
	std::cout << "Massimo: " << massimo << "\n";
	std::cout << "Minimo: " << minimo << "\n";
	std::cout << "Media: " << media << "\n";
	std::cout << "Deviazione standard: " << dev_st << "\n";	
	return 0;
}