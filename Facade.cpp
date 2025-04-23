//Facade(퍼사드) 패턴은 복잡한 서브시스템을 단순화하여 클라이언트가 쉽게 사용할 수 있도록 하는 디자인 패턴입니다.
#include <iostream>
using namespace std;

class FoodDB {
  public:
    FoodDB(string name) {
        getNutritionInfoPrivate(name);
    }
    int getNutritionInfo() { return calorie_; }

  private:
    int calorie_;

    void getNutritionInfoPrivate(string name) { calorie_ = 1000;}
};

class Food {
  public:
    Food(string name) {
        name_ = name;
        FoodDB db(name_);
        calorie_ = db.getNutritionInfo();
    }
    int getNutritionInfo() { return calorie_; }
    void decrease(int calorie) { calorie_ -= calorie;}

  private:
    string name_;
    int calorie_;
};

class Mouse {
  public:
    Mouse(Food* food) {
        food_ = food;
    }
    void eating() { food_->decrease(100); } // 100칼로리 감소

  private:
    Food* food_;
};

class Stomach {
  public:
    Stomach(Food* food) {
        food_ = food;
    }
    void eating() { food_->decrease(200); } // 200칼로리 감소

  private:
    Food* food_;
};

// Facade 클래스
class DigestHandler {
  public:
    DigestHandler(Food* food) {
        food_ = food;
    }
    int digetsResult() {
        Mouse mouse(food_);
        mouse.eating();
        Stomach stomach(food_);
        stomach.eating();
        return food_->getNutritionInfo();
    }

  private:
    Food* food_;
};


int main(int argc, char* argv[]) {
    Food* food = new Food("치킨");
    DigestHandler digestHandler(food);
    cout << digestHandler.digetsResult() << endl; // 복잡한 내부 내용을 숨김
    return 0;
}