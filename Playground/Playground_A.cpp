#include "Playground_A.hpp"

int test_Playground_A_1() {
   WarriorBase_t w1, w2;

   WarriorBase2_t wb2;

   ++wb2.weaponsSkill();
   ++wb2.armor();

   Stat_weaponsSkill ws;

   //cout << ws << endl;
   //cout << w1.weaponsSkill() << endl;

   ++ws;
   ++w1.weaponsSkill();
   ++w1.weaponsSkill();
   ++w1.weaponsSkill();

   cout << w2.weaponsSkill() << endl;
   w2.weaponsSkill() = 100;
   cout << w2.weaponsSkill() << endl;
   w2.weaponsSkill() -= w1.weaponsSkill();
   cout << w2.weaponsSkill() << endl;

   return 0;
}
