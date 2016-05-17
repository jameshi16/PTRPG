#ifndef SKILL_H
#define SKILL_H

#include <string>

class Game; //Forward declaration

class Skill
{
    public:
        Skill();
        virtual void useSkill(Game*) = 0;

        /*gets and sets*/
        std::string getSkillName() { return skillName; }
        std::string setSkillName(std::string s) { return skillName = s; }

        virtual ~Skill();

    protected:

    private:
        std::string skillName = "";
};

#endif // SKILL_H
