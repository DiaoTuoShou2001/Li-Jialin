#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QDesktopWidget>
class guandao {
private:
    std::string name; // 管道名称
    double length;    // 管道长度
    bool underMaintenance;

public:
    guandao(const std::string &name, double length, bool underMaintenance)
            : name(name), length(length), underMaintenance(underMaintenance) {}

    void setname(const std::string &newname) { name = newname; }
    void setlength(double newlength) { length = newlength; }
    void setmaint(bool isunder) { underMaintenance = isunder; }

    std::string getname() const { return name; }
    double getlength() const { return length; }
    bool getmaint() const { return underMaintenance; }
};

class bengzhan {
private:
    std::string name;
    int number;
    int worknumber;
    double xiaolv;

public:
    bengzhan(const std::string &name, int number, int worknumber, double xiaolv)
            : name(name), number(number), worknumber(worknumber), xiaolv(xiaolv) {}

    void setname(const std::string &newname) { name = newname; }
    void setnumber(int newnumber) { number = newnumber; }
    void setworknumber(int newworknumber) { worknumber = newworknumber; }
    void setxiaolv(double newxiaolv) { xiaolv = newxiaolv; }

    std::string getname() const { return name; }
    int getnumber() const { return number; }
    int getworknumber() const { return worknumber; }
    double getxiaolv() const { return xiaolv; }
};

class MainWindow : public QWidget {
Q_OBJECT

private:
    guandao *pipe;
    bengzhan *station;

    QLineEdit *pipeNameInput;
    QLineEdit *pipeLengthInput;
    QLineEdit *stationNameInput;
    QLineEdit *stationNumberInput;
    QLineEdit *stationWorkNumberInput;

public:
    MainWindow() {
        pipe = new guandao("DefaultPipe", 100.0, false);
        station = new bengzhan("DefaultStation", 10, 5, 50.0);

        // 设置窗口大小
        this->resize(QDesktopWidget().availableGeometry(this).size() * 0.5);

        // 管道输入
        QLabel *pipeNameLabel = new QLabel("Pipeline Name:", this);
        pipeNameLabel->move(30, 30); // 设置标签位置

        pipeNameInput = new QLineEdit(this);
        pipeNameInput->setFixedWidth(200); // 设置固定宽度
        pipeNameInput->move(180, 30); // 设置输入框位置

        QLabel *pipeLengthLabel = new QLabel("Pipeline Length:", this);
        pipeLengthLabel->move(30, 70); // 设置标签位置

        pipeLengthInput = new QLineEdit(this);
        pipeLengthInput->setFixedWidth(200); // 设置固定宽度
        pipeLengthInput->move(180, 70); // 设置输入框位置

        QPushButton *updatePipeButton = new QPushButton("Update Pipeline Information", this);
        updatePipeButton->setFixedWidth(300); // 设置固定宽度
        updatePipeButton->move(30, 110); // 设置按钮位置
        connect(updatePipeButton, &QPushButton::clicked, this, &MainWindow::updatePipe);

        // 站点输入
        QLabel *stationNameLabel = new QLabel("Station Name:", this);
        stationNameLabel->move(30, 150); // 设置标签位置

        stationNameInput = new QLineEdit(this);
        stationNameInput->setFixedWidth(200); // 设置固定宽度
        stationNameInput->move(180, 150); // 设置输入框位置

        QLabel *stationNumberLabel = new QLabel("Number of Stations:", this);
        stationNumberLabel->move(30, 190); // 设置标签位置

        stationNumberInput = new QLineEdit(this);
        stationNumberInput->setFixedWidth(200); // 设置固定宽度
        stationNumberInput->move(180, 190); // 设置输入框位置

        QLabel *stationWorkNumberLabel = new QLabel("Number of Jobs:", this);
        stationWorkNumberLabel->move(30, 230); // 设置标签位置

        stationWorkNumberInput = new QLineEdit(this);
        stationWorkNumberInput->setFixedWidth(200); // 设置固定宽度
        stationWorkNumberInput->move(180, 230); // 设置输入框位置

        QPushButton *updateStationButton = new QPushButton("Update Station Information", this);
        updateStationButton->setFixedWidth(300); // 设置固定宽度
        updateStationButton->move(30, 270); // 设置按钮位置
        connect(updateStationButton, &QPushButton::clicked, this, &MainWindow::updateStation);
    }
private slots:
    void updatePipe() {
        std::string name = pipeNameInput->text().toStdString();
        double length = pipeLengthInput->text().toDouble();
        if (length <= 0) {
            QMessageBox::warning(this, "input error", "Pipe length must be greater than 0");
            return;
        }
        pipe->setname(name);
        pipe->setlength(length);
        QMessageBox::information(this, "Successful update", "Pipeline information has been updated");
    }

    void updateStation() {
        std::string name = stationNameInput->text().toStdString();
        int number = stationNumberInput->text().toInt();
        int worknumber = stationWorkNumberInput->text().toInt();

        if (number <= 0 || worknumber <= 0) {
            QMessageBox::warning(this, "input error", "Number of sites and number of jobs must be greater than 0");
            return;
        }
        station->setname(name);
        station->setnumber(number);
        station->setworknumber(worknumber);
        QMessageBox::information(this, "Successful update", "Site information has been updated");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Pipeline and site information management");
    window.show();
    return app.exec();
}

#include "main.moc"
