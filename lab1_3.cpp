#include <iostream>
#include <memory>
using namespace std;

class Logger {
    public:
        virtual void Log(string&) = 0;
};
    
class FileLogger: public Logger {
    public:
        void Log(string& text) {
            cout << "Saving log in file: " << text << "\n";
        }
};

class DatabaseLogger: public Logger {
    public:
        void Log(string& text) {
            cout << "Saving log to DB: " << text << "\n";
        }
};
    
class SmtpMailer {
    shared_ptr<Logger> logger;
public:
    SmtpMailer(shared_ptr<Logger> log) {
        logger = shared_ptr<Logger>(log);
    }

    void setLog(shared_ptr<Logger> log) {
        logger = shared_ptr<Logger>(log);
    }

    // getter?

    void SendMessage(string message) {
        cout << "Sending message.\n";
        logger->Log(message);
    }
};

int main() {
    shared_ptr<FileLogger> flog = make_shared<FileLogger>();
    shared_ptr<DatabaseLogger> dblog = make_shared<DatabaseLogger>();
    
    SmtpMailer mailer(flog);
    mailer.SendMessage("First test msg");
    
    //cout << "Current log type: " << mailer.getLog() << "\n";

    mailer = SmtpMailer(dblog);
    mailer.SendMessage("Second test msg");

    return 0;
}