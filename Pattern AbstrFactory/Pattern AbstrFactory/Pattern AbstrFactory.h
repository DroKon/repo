#pragma once
#include <iostream>
#include <string>

using namespace std;
// ����������� ��������
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


//���������� ��������
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


//����������� �������
struct AbstractFactory {
  virtual LowBilding* createLowBilding() = 0; // ��������� ��� �������� �������� ��������
  virtual HighBilding* createHighBilding() = 0;
};

//���������� ������� �������� ����� ��������
struct ResidentialFactory : public AbstractFactory {
  virtual LowBilding* createLowBilding() {
    return new ResidentialCottedgeLowBilding();
  }
  virtual HighBilding* createHighBilding() {
    return new ResidentialHouseHighBilding();
  }
};

//���������� ������� �������� �� ������� ��������
struct NoResidentialFactory : public AbstractFactory {
  virtual LowBilding* createLowBilding() {
    return new SchoolLowBilding();
  }
  virtual HighBilding* createHighBilding() {
    return new OfficeHighBilding();
  }
};
