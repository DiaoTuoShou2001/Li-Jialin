#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

  void display() const {
    std::cout << "Name: " << name << ", Length: " << length
              << ", Under Maintenance: " << (underMaintenance ? "Yes" : "No")
              << "\n";
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

  void setname(const std::string &newname) { name = newname; }
  void setnumber(int newnumber) { number = newnumber; }
  void setworknumber(int newworknumber) { worknumber = newworknumber; }
  void setxiaolv(double newxiaolv) { xiaolv = newxiaolv; }

  std::string getname() const { return name; }
  int getnumber() const { return number; }
  int getworknumber() const { return worknumber; }
  double getxiaolv() const { return xiaolv; }

  void display() const {
    std::cout << "Name: " << name << ", total number: " << number
              << ", worknumber: " << worknumber << ", work efficiency "
              << xiaolv << "\n";
  }
};
void saveData(const std::vector<guandao> &pipes,
              const std::vector<bengzhan> &stations) {
  std::ofstream outFile("data.txt");
  if (outFile.is_open()) {
    for (const auto &pipe : pipes) {
      outFile << pipe.getname() << " " << pipe.getlength() << " "
              << pipe.getmaint() << "\n";
    }
    outFile << "---\n";
    for (const auto &station : stations) {
      outFile << station.getname() << " " << station.getnumber() << " "
              << station.getworknumber() << " " << station.getxiaolv() << "\n";
    }
    outFile.close();
    std::cout << "Data saved to file\n";
  } else {
    std::cerr << "Unable to open file for writing\n";
  }
}
void loadData(std::vector<guandao> &pipes, std::vector<bengzhan> &stations) {
    std::ifstream inFile("data.txt");
    if (inFile.is_open()) {
        pipes.clear();
        stations.clear();

        std::string line;
        bool readingStations = false;

        while (std::getline(inFile, line)) {
            if (line == "---") {
                readingStations = true;
                continue;
            }

            std::istringstream iss(line);
            if (!readingStations) {
                // 读取管道数据
                std::string name;
                double length;
                bool maint;
                if (iss >> name >> length >> maint) {
                    pipes.emplace_back(name, length, maint);
                }
            } else {
                // 读取站点数据
                std::string name;
                int number, workNumber;
                double xiaolv;
                if (iss >> name >> number >> workNumber >> xiaolv) {
                    stations.emplace_back(name, number, workNumber, xiaolv);
                }
            }
        }

        inFile.close();
    std::cout << "Data loaded from file\n";
  } else {
    std::cerr << "Unable to open file for reading\n";
  }
}
void displaySpecificPipe(const std::vector<guandao> &pipes) {
  std::string searchName;
  std::cout << "Enter the pipeline name to display: ";
  std::cin >> searchName;

  bool found = false;
  for (const auto &pipe : pipes) {
    if (pipe.getname() == searchName) {
      pipe.display();
      found = true;
      break;
    }
  }

  if (!found) {
    std::cerr << "Pipeline not found.\n";
  }
}
void displaySpecificstation(const std::vector<bengzhan> &stations) {
  std::string searchName;
  std::cout << "Enter the station name to display: ";
  std::cin >> searchName;

  bool found = false;
  for (const auto &station : stations) {
    if (station.getname() == searchName) {
      station.display();
      found = true;
      break;
    }
  }
}

int main() {
  std::vector<guandao> pipes;
  std::vector<bengzhan> stations;

  loadData(pipes, stations);

  guandao pipe("DefaultPipe", 100.0, false);
  bengzhan station("DefaultStation", 10, 5, 50.0);

  while (true) {
    std::cout << "Select operation:\n";
    std::cout << "1. Update pipeline information\n";
    std::cout << "2. Update station information\n";
    std::cout << "3. Display pipeline information\n";
    std::cout << "4. Display station information\n";
    std::cout << "5. Save data to file\n";
    std::cout << "6. Display specific pipeline information\n";
    std::cout << "7. Display specific station information\n";
    std::cout << "0. End program\n";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1: {
      std::string name;
      double length;
      bool maint;

      std::cout << "输入管道名称: ";
      std::cin >> name;
      std::cout << "输入管道长度: ";
      std::cin >> length;

      if (length <= 0) {
        std::cerr << "错误: 管道长度必须大于0\n";
        break;
      }

      std::cout << "Is it under maintenance (1: yes, 0: no): ";
      std::cin >> maint;
      std::cout << maint;
      if ((maint != 0) && (maint != 1)) {
        std::cerr << "Error: Please enter 0 or 1\n";
        break;
      }

      guandao newPipe(name, length, maint);
      pipes.push_back(newPipe); // 添加到向量中
      std::cout << "Pipeline Information Update\n";
      break;
    }
    case 2: {
      std::string name;
      int number, worknumber;

      std::cout << "输入站点名称: ";
      std::cin >> name;
      std::cout << "输入站点数量: ";
      std::cin >> number;
      std::cout << "输入工作数量: ";
      std::cin >> worknumber;

      if (number <= 0 || worknumber <= 0) {
        std::cerr << "Error: Number of sites and number of jobs must be "
                     "greater than 0\n";
        break;
      }

      double xiaolv;
      std::cout << "输入效率: ";
      std::cin >> xiaolv;

      bengzhan newStation(name, number, worknumber, xiaolv);
      stations.push_back(newStation); // 添加到向量中
      saveData(pipes, stations);
      std::cout << "Site information has been updated\n";
      break;
    }
    case 3: {
      for (const auto &pipe : pipes) {
        pipe.display();
      }
      break;
    }

    case 4: {
      for (const auto &station : stations) {
        // 显示站点信息
          station.display();
      }

      break;
    }
    case 5: {
      saveData(pipes, stations);
      break;
    }
    case 6: {
      displaySpecificPipe(pipes);
      break;
    }
    case 7: {
      displaySpecificstation(stations);
      break;
    }
    case 0:
      saveData(pipes, stations); // 退出前保存数据
      return 0;
    default:
      std::cerr << "Invalid choice, please try again.\n";
    }
  }

  return 0;
}
