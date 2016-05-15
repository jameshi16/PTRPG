#ifndef SKILL_H
#define SKILL_H

class Game; //Forward declaration

class Skill
{
    public:
        Skill();

        virtual void useSkill(Game*);

        virtual ~Skill();

    protected:

    private:
};

#endif // SKILL_H
