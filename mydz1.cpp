#include "any"
#include "ostream"
#include "string"

class guandao {

private:
  std::string name; // 管道名称
  double length;    // 管道长度
  bool underMaintenance;
  // guandao 管道
public:
  guandao(const std::string &name, double length, bool underMaintenance)
      : name(name), length(length), underMaintenance(underMaintenance) {}

  guandao() : length(0.0), underMaintenance(false) {}

  void setname(const std::string newname) { name = newname; }
  void std::string getname() const { return name; }

  void setlenth(double newlenth) {
    if (newlenth > 0) {
      length = newlenth;
    } else {
      std::cerr << "cuowuchangdu" << std::endl;
    }
  }

  void getlenth() const { return length; }
  void setmaint(bool isunder) { underMaintenance = isunder; }
  void getmaint() const { return underMaintenance; }

  void displayifo() {
    std::cout << "Pipe name:" << name << "\nlength:" << length
              << "\nUnder Maintenance:" << (underMaintenance ? "yes" : "no")
              << std::endl;
  }
} 




int main() {
  guandao1 = guandao("shenzhou", 250.0, flase);
  guandao1.displayifo()

      return 0;
}
