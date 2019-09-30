#ifndef SIMPLEGAMEENGINE_GAME_HPP
#define SIMPLEGAMEENGINE_GAME_HPP

class Game {
    public:
        Game();

        bool isPaused() const;
        bool isRunning() const;
        void setRunning(bool running);
        void setPaused(bool paused);

    private:
        bool running;
        bool paused;
};

#endif //SIMPLEGAMEENGINE_GAME_HPP
