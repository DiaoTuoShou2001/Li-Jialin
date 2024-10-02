#include <iostream>
#include <string>

class guandao {
private:
  std::string name; // 管道名称
  double length;    // 管道长度
  bool underMaintenance;

public:
  guandao(const std::string &name, double length, bool underMaintenance)
      : name(name), length(length), underMaintenance(underMaintenance) {}

  guandao() : name(""), length(0.0), underMaintenance(false) {}

  void setname(const std::string &newname) { name = newname; }
  std::string getname() const { return name; }

  void setlength(double newlength) {
    if (newlength > 0) {
      length = newlength;
    } else {
      std::cerr << "Error: Length must be greater than 0." << std::endl;
    }
  }

  double getlength() const { return length; }
  void setmaint(bool isunder) { underMaintenance = isunder; }
  bool getmaint() const { return underMaintenance; }

  void displayinfo() const {
    std::cout << "Pipe name: " << name << "\nLength: " << length
              << "\nUnder Maintenance: " << (underMaintenance ? "Yes" : "No")
              << std::endl;
  }
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

  bengzhan() : name(""), number(0), worknumber(0), xiaolv(0.0) {}

  void setname(const std::string &newname) { name = newname; }
  std::string getname() const { return name; }

  void setnumber(int newnumber) {
    if (newnumber > 0) {
      number = newnumber;
    } else {
      std::cerr << "Error: Quantity cannot be less than or equal to 0."
                << std::endl;
    }
  }

  void setworknumber(int newworknumber) { worknumber = newworknumber; }

  void setxiaolv(double newxiaolv) {
    newxiaolv = static_cast<double>(number) / worknumber;
    xiaolv = newxiaolv;
  }
  void getinfo() {
    std::cout << "Pipe name: " << name << "\nnumber: " << number
              << "\nworknumber" << worknumber << "\ngongzuo xiaolv: " << xiaolv
              << std::endl;
  }
  int getnumber() const { return number; }
  int getworknumber() const { return worknumber; }
  double getxiaolv() const { return xiaolv; }

  void displayinfo() const {
    std::cout << "Station name: " << name << "\nNumber: " << number
              << "\nWorking Number: " << worknumber
              << "\nEfficiency: " << xiaolv << std::endl;
  }
};

int main() {
  guandao guandao1("shenzhou", 250.0, false);
  guandao1.displayinfo();
  bengzhan bengzhan1("shenzhou1", 4, 2, 50.0);
  bengzhan1.displayinfo();
  return 0;
}
