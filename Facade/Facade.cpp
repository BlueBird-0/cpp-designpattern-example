//Facade(퍼사드) 패턴은 복잡한 서브시스템을 단순화하여 클라이언트가 쉽게 사용할 수 있도록 하는 디자인 패턴입니다.
#include <iostream>
using namespace std;

class FoodDB {
  public:
    FoodDB(string name) {
        getNutritionInfoPrivate(name);
    }
    int getNutritionInfo() { return m_calorie; }

  private:
    int m_calorie;

    void getNutritionInfoPrivate(string name) { m_calorie = 1000;}
};

class Food {
  public:
    Food(string name) : m_name(name) {
        // name_ = name;
        FoodDB db(m_name);
        m_calorie = db.getNutritionInfo();
    }
    int getNutritionInfo() { return m_calorie; }
    void decrease(int calorie) { m_calorie -= calorie;}

  private:
    string m_name;
    int m_calorie;
};

class Mouse {
  public:
    Mouse(Food* food) : m_food(food) {}
    void eating() { m_food->decrease(100); } // 100칼로리 감소

  private:
    Food* m_food;
};

class Stomach {
  public:
    Stomach(Food* food) : m_food(food) {}
    void eating() { m_food->decrease(200); } // 200칼로리 감소

  private:
    Food* m_food;
};

// Facade 클래스
class DigestHandler {
  public:
    DigestHandler(Food* food) : m_food(food) {}
    int digetsResult() {
        Mouse mouse(m_food);
        mouse.eating();
        Stomach stomach(m_food);
        stomach.eating();
        return m_food->getNutritionInfo();
    }

  private:
    Food* m_food;
};