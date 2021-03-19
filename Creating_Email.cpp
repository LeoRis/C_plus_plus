#include <iostream>
#include <cstring>

using namespace std;
enum {AddLen = 100, SubLen = 200, BodyLen = 1000};

class EMail{
private:
    char to[AddLen];
    char from[AddLen];
    char subject[SubLen];
    char body[BodyLen];

public:
    EMail(char *to, char *from, char *subject, char *body){
        strncpy(this->to, to, AddLen - 1);
        strncpy(this->from, from, AddLen - 1);
        strncpy(this->subject, subject, SubLen - 1);
        strncpy(this->body, body, BodyLen - 1);
        to[AddLen - 1] = subject[SubLen - 1] = 0;
        from[AddLen - 1] = subject[SubLen - 1] = body[BodyLen - 1] = 0;
    }
    ~EMail(){}

    void setTo(char const *n){
        strncpy(to, n, AddLen - 1);
        to[AddLen - 1];
    }

    void setFrom(char const *n){
        strncpy(from, n, AddLen - 1);
        from[AddLen - 1];
    }

    void setSubject(char const *n){
        strncpy(subject, n, SubLen - 1);
        subject[SubLen - 1];
    }

    void setBody(char const *n){
        strncpy(body, n, BodyLen - 1);
        body[BodyLen - 1];
    }

    const char *getTo(){return to;}
    const char *getFrom(){return from;}
    const char *getSubject(){return subject;}
    const char *getBody(){return body;}

    void Print(){
        cout << "To: " << to << endl;
        cout << "From: " << from << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }
};

bool checkEmail(char *address);

int main(){

    char to[100], from[100], subject[200], body[1000];

    cout << "Who is this message for? " << endl;
    cin >> to;

    if(checkEmail(to)){

        cout << "Insert who is this email from" << endl;
        cin >> from;
        cout << "Insert subject" << endl;
        cin >> subject;
        cout << "Insert content" << endl;
        cin >> body;

        EMail message(to, from, subject, body);
        cout << "Sent: " << endl;
        message.Print();

    }else{

        cout << "Wrong address!" << endl;

    }

    return 0;
}

bool checkEmail(char *address){

    int count = 0;

    while(*address != 0){
        if('@' == *address++){
            count++;
        }
    }

    return (1 == count);
}
