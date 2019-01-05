#ifndef SIMPLEGAMEENGINE_GAME_HPP
#define SIMPLEGAMEENGINE_GAME_HPP

class Game {
    private:
        bool running;

    public:
        Game();

        bool isRunning() const;
        void setRunning( bool running );
};

#endif //SIMPLEGAMEENGINE_GAME_HPP
