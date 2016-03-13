#pragma once


#include <tuple>
#include <iostream>
#include <vector>

using namespace std;

enum class Stats_e {
   WS,
   BS,
   S,
   T,
   W,
   I,
   A,
   Ld,
   SV,
   Invul,
   MAX,
};

template <typename T, Stats_e S>
struct Stat_t {
   const Stats_e ID = S;
   using ME = T;
   using PARENT = Stat_t<T, S>;
protected:
   int m_val = 0;
public:
   Stat_t<T, S>() {

   }

   Stat_t<T, S>(int val) {
      m_val = val;
   }

   operator int() const {
      return m_val;
   }

   PARENT& operator=(int val) {
      m_val = val;
      return *this;
   }
   PARENT& operator+=(int val) {
      m_val += val;
      return *this;
   }
   PARENT& operator-=(int val) {
      m_val -= val;
      return *this;
   }

   PARENT& operator=(const PARENT &other) {
      m_val = static_cast<int>(other);
      return *this;
   }
   PARENT& operator+=(const PARENT &other) {
      m_val += static_cast<int>(other);
      return *this;
   }
   PARENT& operator-=(const PARENT &other) {
      m_val -= static_cast<int>(other);
      return *this;
   }

   PARENT operator++(int val) {
      m_val++;
      return *this;
   }
   PARENT operator--(int val) {
      m_val--;
      return *this;
   }
   PARENT operator++() {
      m_val++;
      return *this;
   }
   PARENT operator--() {
      m_val--;
      return *this;
   }
};

struct Stat_weaponsSkill : Stat_t<Stat_weaponsSkill, Stats_e::WS> {
   Stat_weaponsSkill() : PARENT() {}
   Stat_weaponsSkill(int val) : PARENT(val) {}

   auto& weaponsSkill() { return const_cast<ME&>(*this); }
   const auto& weaponsSkill() const { return const_cast<const ME&>(*this); }
};

struct Stat_ballisticsSkill : Stat_t<Stat_ballisticsSkill, Stats_e::BS> {
   Stat_ballisticsSkill() : PARENT() {}
   Stat_ballisticsSkill(int val) : PARENT(val) {}

   auto& ballisticSkill() { return const_cast<ME&>(*this); }
   const auto& ballisticSkill() const { return const_cast<ME&>(*this); }
};

struct Stat_invul : Stat_t<Stat_invul, Stats_e::Invul> {
   Stat_invul() : PARENT() {}
   Stat_invul(int val) : PARENT(val) {}

   auto& invul() { return const_cast<ME&>(*this); }
   const auto& invul() const { return const_cast<ME&>(*this); }
};

struct Stat_strength : Stat_t<Stat_strength, Stats_e::S> {
   Stat_strength() : PARENT() {}
   Stat_strength(int val) : PARENT(val) {}

   auto& strength() { return const_cast<ME&>(*this); }
   const auto& strength() const { return const_cast<ME&>(*this); }
};

struct Stat_toughness : Stat_t<Stat_toughness, Stats_e::T> {
   Stat_toughness() : PARENT() {}
   Stat_toughness(int val) : PARENT(val) {}

   auto& toughness() { return const_cast<ME&>(*this); }
   const auto& toughness() const { return const_cast<ME&>(*this); }
};

struct Stat_wounds : Stat_t<Stat_wounds, Stats_e::W> {
   Stat_wounds() : PARENT() {}
   Stat_wounds(int val) : PARENT(val) {}

   auto& wounds() { return const_cast<ME&>(*this); }
   const auto& wounds() const { return const_cast<ME&>(*this); }
};

struct Stat_initiative : Stat_t<Stat_initiative, Stats_e::I> {
   Stat_initiative() : PARENT() {}
   Stat_initiative(int val) : PARENT(val) {}

   auto& initiative() { return const_cast<ME&>(*this); }
   const auto& initiative() const { return const_cast<ME&>(*this); }
};

struct Stat_attacks : Stat_t<Stat_attacks, Stats_e::A> {
   Stat_attacks() : PARENT() {}
   Stat_attacks(int val) : PARENT(val) {}

   auto& attacks() { return const_cast<ME&>(*this); }
   const auto& attacks() const { return const_cast<ME&>(*this); }
};

struct Stat_leadership : Stat_t<Stat_leadership, Stats_e::Ld> {
   Stat_leadership() : PARENT() {}
   Stat_leadership(int val) : PARENT(val) {}

   auto& leadership() { return const_cast<ME&>(*this); }
   const auto& leadership() const { return const_cast<ME&>(*this); }
};

struct Stat_armor : Stat_t<Stat_armor, Stats_e::SV> {
   Stat_armor() : PARENT() {}
   Stat_armor(int val) : PARENT(val) {}

   auto& armor() { return const_cast<ME&>(*this); }
   const auto& armor() const { return const_cast<ME&>(*this); }
};

class WarriorBase_t
   : public Stat_weaponsSkill
   , public Stat_ballisticsSkill
   , public Stat_invul
   , public Stat_strength
   , public Stat_toughness
   , public Stat_wounds
   , public Stat_initiative
   , public Stat_attacks
   , public Stat_leadership
   , public Stat_armor {
public:
   WarriorBase_t() {}
};

template <typename ... Bases>
class WarriorBase_template_t : public Bases...
{
public:
   WarriorBase_template_t() {}
};

using WarriorBase2_t = WarriorBase_template_t<Stat_weaponsSkill, Stat_armor>;

int test_Playground_A_1();

#if 0

#define MakeStat(name, stat)                                           \
struct Stat_ ## name : Stat_t<Stat_ ## name, Stats_e::stat> {          \
   Stat_ ## name()        : PARENT() {}                                \
   Stat_ ## name(int val) : PARENT(val) {}                             \
   auto&        name()       { return const_cast<ME&>(*this); }        \
   const auto&  name() const { return const_cast<const ME&>(*this); }  \
};

MakeStat(weaponsSkill, WS);
MakeStat(ballisticsSkill, BS);
MakeStat(invul, Invul);
MakeStat(strength, S);
MakeStat(toughness, T);
MakeStat(wounds, W);
MakeStat(initiative, I);
MakeStat(attacks, A);
MakeStat(leadership, Ld);
MakeStat(armor, SV);

#endif
