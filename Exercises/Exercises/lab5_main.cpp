void print(const vector<Time> &v) 
{
	for(auto &t : v) {
		cout << t << endl;
	}
}



int main() {
	Time time1, time2, duration, duration2;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1<time2) {
		duration = time2 - time1;
		cout << "Starting time was " << time1 << endl;
		duration2 = time1 - time2;
	} else {
		duration = time1 - time2;
		cout << "Starting time was " << time2 << endl;
		duration2 = time2 - time1;

	}
	cout << "Duration was " << duration << endl;

	// check that we don't get negative times
	cout << "Duration2 was " << duration2 << endl;


	vector<Time> tv(5); 
	for(auto &t : tv) {
		t.read("Enter time:");
	}

	cout << "Times: " << endl;
	print(tv);
	
	Time sum;
	for(auto t : tv) {
		sum = sum + t;
	}
	
	cout << "Sum of times: " << sum << endl;
	
	cout << "Post-increment: " << endl;
	print(tv);
	for(auto &t : tv) {
		cout << t++ << endl;
	}
	
	print(tv);

	cout << "Pre-increment: " << endl;
	for(auto &t : tv) {
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "Sorted times: " << endl;
	print(tv);

	return 0;
}

