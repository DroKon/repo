#pragma once
#include <iostream>
#include <string>

using namespace std;
// Абстрактные продукты
struct LowBilding {
  string status;
  virtual void Bilding() = 0;
  virtual string get_status() { return status; }
};

struct HighBilding {
  string status;
  virtual void Bilding() = 0;
  virtual string get_status() { return status; }
};


//Конкретные продукты
struct  ResidentialCottedgeLowBilding : public LowBilding {
  virtual void Bilding() {
    string status = "ResidentialCottedgeLowBilding::Bilding resident cott";
  }
  string get_status() { return status; }
};

struct SchoolLowBilding : public LowBilding {
  virtual void Bilding() {
    string status = "SchoolLowBilding::Bilding school";
  }
  string get_status() { return status; }
};

struct ResidentialHouseHighBilding : public HighBilding {
  virtual void Bilding() {
    string status = "ResidentialHouseHighBilding ::Bilding ResidentialHouse";
  }
  string get_status() { return status; }
};

struct OfficeHighBilding : public HighBilding {
  virtual void Bilding() {
    string status = "OfficeHighBilding::Bilding Office";
  }
  string get_status() { return status; }
};


//Абстрактная фабрика
struct AbstractFactory {
  virtual LowBilding* createLowBilding() = 0; // интерфейс для создания семейств объектов
  virtual HighBilding* createHighBilding() = 0;
};

//Конкретная фабрика создания жилых построек
struct ResidentialFactory : public AbstractFactory {
  virtual LowBilding* createLowBilding() {
    return new ResidentialCottedgeLowBilding();
  }
  virtual HighBilding* createHighBilding() {
    return new ResidentialHouseHighBilding();
  }
};

//Конкретная фабрика создания не нежилых построек
struct NoResidentialFactory : public AbstractFactory {
  virtual LowBilding* createLowBilding() {
    return new SchoolLowBilding();
  }
  virtual HighBilding* createHighBilding() {
    return new OfficeHighBilding();
  }
};
