#ifndef CLASSES_H
#define CLASSES_H

#include <string>

using namespace std;

class ClasseBase
{
public:
    int var_public;
private:
    int var_private;
protected:
    int var_protected;

public:
 void set1(int i);
 void set2(int i);
 void set3(int i);

 int get1();
 int get2();
 int get3();
};


class A2 : private ClasseBase 
{
public:
	int var_public2;
private:
	int var_private2;
protected:
	int var_protected2;


public:
 void set1(int i);
 void set2_a(int i);
 void set3(int i);

 int get1_a();
 string get2_a();
 int get3_a();

 void set1_2(int i);
 void set2_2(int i);
 void set3_2(int i);

 int get1_2();
 int get2_2();
 int get3_2();


};


class A3 : public A2
{
public:
	int var_public3;
private:
	int var_private3;
protected:
	int var_protected3;

public:
 void set1_a2(int i);
 void set2_a2(int i);
 void set3_a2(int i);

 string get1_a2();
 string get2_a2();
 string get3_a2();

 void set1_2(int i);
 void set2_2a2(int i);
 void set3_2(int i);

 int get1_2a2();
 string get2_2a2();
 int get3_2a2();

 void set1_3(int i);
 void set2_3(int i);
 void set3_3(int i);

 int get1_3();
 int get2_3();
 int get3_3();

}; 


class ClassePublica : public ClasseBase
{
public:
	int var_public2;
private:
	int var_private2;
protected:
	int var_protected2;
	
public:
    ClassePublica()
    {
        var_public = 0; 
        var_protected = 0; 
    }


public:
  void set1(int i);
 void set2_a(int i);
 void set3(int i);

 int get1_a();
 string get2_a();
 int get3_a();

 void set1_2(int i);
 void set2_2(int i);
 void set3_2(int i);

 int get1_2();
 int get2_2();
 int get3_2();
}; 


class ClassePrivada : private ClasseBase
{
public:
    ClassePrivada()
    {
        var_public = 0; 
        var_protected = 0; 
    }

public:
void set1(int i);
 void set2_a(int i);
 void set3(int i);

 int get1_a();
 string get2_a();
 int get3_a();

};

class OverloadPrivada : private ClasseBase
{
	public:
    	int var_public;
	private:
    	int var_private;
	protected:
    	int var_protected;	

public:
 void set1(int i);
 void set2(int i);
 void set3(int i);

 int get1();
 int get2();
 int get3();

};

#endif