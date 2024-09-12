@ -1,2 +1,99 @@
# Auto detect text files and perform LF normalization
* text=auto
#include <iostream>
#include <vector>
#include <string>

// 定义管道类
class Pipe {
private:
    std::string name; // 公里标记（名称）
    double length; // 长度
    double diameter; // 直径
    bool underRepair; // 维修中属性

public:
    // 构造函数
    Pipe(std::string n, double l, double d) : name(n), length(l), diameter(d), underRepair(false) {}

    // 设置和获取方法
    void setName(std::string n) { name = n; }
    void setLength(double l) { length = l; }
    void setDiameter(double d) { diameter = d; }
    void setUnderRepair(bool ur) { underRepair = ur; }

    std::string getName() const { return name; }
    double getLength() const { return length; }
    double getDiameter() const { return diameter; }
    bool isUnderRepair() const { return underRepair; }

    // 显示管道信息
    void display() const {
        std::cout << "Pipe Name: " << name << ", Length: " << length << " km, Diameter: " << diameter << " m, Under Repair: " << (underRepair ? "Yes" : "No") << std::endl;
    }
};

// 定义压缩机站类
class CompressorStation {
private:
    std::string name; // 名称
    int totalWorkshops; // 总车间数
    int activeWorkshops; // 激活的车间数

public:
    // 构造函数
    CompressorStation(std::string n, int tw) : name(n), totalWorkshops(tw), activeWorkshops(0) {}

    // 设置和获取方法
    void setName(std::string n) { name = n; }
    void setTotalWorkshops(int tw) { totalWorkshops = tw; }
    void setActiveWorkshops(int aw) { activeWorkshops = aw; }

    std::string getName() const { return name; }
    int getTotalWorkshops() const { return totalWorkshops; }
    int getActiveWorkshops() const { return activeWorkshops; }

    // 显示压缩机站信息
    void display() const {
        std::cout << "Compressor Station Name: " << name << ", Total Workshops: " << totalWorkshops << ", Active Workshops: " << activeWorkshops << std::endl;
    }

    // 启动车间
    void startWorkshop() {
        if (activeWorkshops < totalWorkshops) {
            activeWorkshops++;
            std::cout << "Workshop started at " << name << ". Active workshops: " << activeWorkshops << std::endl;
        } else {
            std::cout << "All workshops are already running at " << name << "." << std::endl;
        }
    }

    // 停止车间
    void stopWorkshop() {
        if (activeWorkshops > 0) {
            activeWorkshops--;
            std::cout << "Workshop stopped at " << name << ". Active workshops: " << activeWorkshops << std::endl;
        } else {
            std::cout << "No workshops are running at " << name << "." << std::endl;
        }
    }
};

int main() {
    // 创建管道和压缩机站对象
    Pipe pipe("Pipe A", 100.0, 1.2);
    CompressorStation compressorStation("Compressor Station 1", 5);

    // 显示信息
    pipe.display();
    compressorStation.display();

    // 模拟操作
    pipe.setUnderRepair(true); // 设置管道维修状态
    compressorStation.startWorkshop(); // 启动车间
    compressorStation.stopWorkshop(); // 停止车间

    // 再次显示信息
    pipe.display();
    compressorStation.display();

    return 0;
}
