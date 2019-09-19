#include<thread>
#include<iostream>
#include<atomic>
using namespace std;

atomic<bool> ready(false);
atomic<bool> ready1(false);
atomic<bool> ready2(false);

std::atomic<int> counter(0);
std::atomic<int> counter1(0);
std::atomic<int> counter2(0);

void count1m(int id){
	while (!ready){
		std::this_thread::yield();
	}
	for (volatile int i=1; i<55; ++i){}
	
	
	
	++counter;
	if (counter <=6){
		std::cout<<id<<" ";
}
}

void countagain(int num){
	while (!ready1){
		std::this_thread::yield();
	}
	for (volatile int q=1; q<55; ++q){}
	
	
	
	++counter1;
	if (counter1 <=6){
		std::cout<<num<<" ";
}
}

void countonce(int num2){
	while (!ready2){
		std::this_thread::yield();
	}
	for (volatile int a=1; a<55; ++a){}
	
	
	
	++counter2;
	if (counter2 <=6){
		std::cout<<num2<<" ";

}
}
int main()
{
	std::cout << "The Winning Numbers Are! \n";
	std::thread threads[55];
	std::cout << "\nFirst Winner: \n";
	for (int i=0; i<55; ++i) threads[i]=std::thread(count1m, i);
	ready = true;
	for (auto& th : threads)th.join();
	std:: cout << '\n';
	
	
	std::thread threading[55];
	std::cout << "\nSecond Winner: \n";
	for (int q=0; q<55; ++q) threading[q]=std::thread(countagain, q);
	ready1 = true;
	for (auto& th : threading)th.join();
	std:: cout << '\n';
	
	std::thread threadingko[55];
	std::cout << "\nThird Winner: \n";
	for (int a=0; a<55; ++a) threadingko[a]=std::thread(countonce, a);
	ready2 = true;
	for (auto& th : threadingko)th.join();
	std:: cout << '\n';	
	
	return 0;
}
