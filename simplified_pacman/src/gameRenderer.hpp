//#ifndef GAMERENDERER_H
//#define GAMERENDERER_H
//
//class GameRenderer
//{
//public:
//    static GameRenderer * GetInstance()
//    {
//        if(Instance == NULL)  //判断是否第一次调用
//            Instance = new CSingleton();
//        return Instance;
//    }
//private:
//    GameRenderer()
//    {
//        gRenderer = NULL;
//    }
////    SDL_Renderer* gRenderer;
//    static GameRenderer *Instance;
//    class CGarbo   //它的唯一工作就是在析构函数中删除CSingleton的实例
//    {
//    public:
//        ~CGarbo()
//        {
//            if(GameRenderer::Instance)
//                delete GameRenderer::Instance;
//        }
//    };
//    static CGarbo Garbo;  //定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数
//}
//
//
//
//#endif
