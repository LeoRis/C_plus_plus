#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel {

public:
	string Name;
	string OwnerName;
	int SubscriberCount;
	list<string> PublishedVideoTitles;
};

int main() {

	YouTubeChannel ytChannel;
	ytChannel.Name = "The Pirate";
	ytChannel.OwnerName = "Sparrow";
	ytChannel.SubscriberCount = 5000;
	ytChannel.PublishedVideoTitles = { "C++ for begginers", "Intermediate Course", "Advanced C++" };

	cout << "Name: " << ytChannel.Name << endl;
	cout << "Owner: " << ytChannel.OwnerName << endl;
	cout << "Subscribers: " << ytChannel.SubscriberCount<< endl;
	cout << "Videos: " << endl;

	for (string videoTitle : ytChannel.PublishedVideoTitles) {
		cout << videoTitle << endl;
	}
}