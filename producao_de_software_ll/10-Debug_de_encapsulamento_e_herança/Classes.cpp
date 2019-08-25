#include "Classes.hpp"

void ClasseBase::set1(int i) {var_public=i;}
void ClasseBase::set2(int i) {var_private=i;}
void ClasseBase::set3(int i) {var_protected=i;}

void ClassePublica::set1(int i) {var_public=i;}
void ClassePublica::set2_a(int i) {}
void ClassePublica::set3(int i) {var_protected=i;}

void A2::set1(int i) {var_public=i;}
void A2::set2_a(int i) {}
void A2::set3(int i) {var_protected=i;}

void A3::set1_a2(int i) {set1(i);}
void A3::set2_a2(int i) {}
void A3::set3_a2(int i) {set3(i);}

void A2::set1_2(int i) {var_public2=i;}
void A2::set2_2(int i) {var_private2=i;}
void A2::set3_2(int i) {var_protected2=i;}

void A3::set1_2(int i) {var_public2=i;}
void A3::set2_2a2(int i) {}
void A3::set3_2(int i) {var_protected2=i;}

void ClassePublica::set1_2(int i) {var_public2=i;}
void ClassePublica::set2_2(int i) {var_private2=i;}
void ClassePublica::set3_2(int i) {var_protected2=i;}

void ClassePrivada::set1(int i) {var_public=i;}
void ClassePrivada::set2_a(int i) {}
void ClassePrivada::set3(int i) {var_protected=i;}

void A3::set1_3(int i) {var_public3=i;}
void A3::set2_3(int i) {var_private3=i;}
void A3::set3_3(int i) {var_protected3=i;}

void OverloadPrivada::set1(int i) {var_public=i;}
void OverloadPrivada::set2(int i) {var_private=i;}
void OverloadPrivada::set3(int i) {var_protected=i;}


int ClasseBase::get1() {return var_public;}
int ClasseBase::get2() {return var_private;}
int ClasseBase::get3() {return var_protected;}

int OverloadPrivada::get1() {return var_public;}
int OverloadPrivada::get2() {return var_private;}
int OverloadPrivada::get3() {return var_protected;}

int ClassePrivada::get1_a() {return var_public;} 
string ClassePrivada::get2_a() {return "Inacessivel";}
int ClassePrivada::get3_a() {return var_protected;}

int ClassePublica::get1_a() {return var_public;} 
string ClassePublica::get2_a() {return "Inacessivel";}
int ClassePublica::get3_a() {return var_protected;}

int A2::get1_a() {return var_public;} 
string A2::get2_a() {return "Inacessivel";}
int A2::get3_a() {return var_protected;}

string A3::get1_a2() {return "Inacessivel";} 
string A3::get2_a2() {return "Inacessivel";}
string A3::get3_a2() {return "Inacessivel";}

int ClassePublica::get1_2() {return var_public2;}
int ClassePublica::get2_2() {return var_private2;}
int ClassePublica::get3_2() {return var_protected2;}

int A2::get1_2() {return var_public2;}
int A2::get2_2() {return var_private2;}
int A2::get3_2() {return var_protected2;}

int A3::get1_2a2() {return var_public2;}
string A3::get2_2a2() {return "Inacessivel";}
int A3::get3_2a2() {return var_protected2;}

int A3::get1_3() {return var_public3;}
int A3::get2_3() {return var_private3;}
int A3::get3_3() {return var_protected3;}