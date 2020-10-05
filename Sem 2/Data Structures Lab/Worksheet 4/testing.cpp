#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 3) { // We expect 3 arguments: the program name, the source path and the destination path
        std::cerr << "Usage: " << argv[0] <<" SOURCE DESTINATION" << std::endl;
        return 1;
    }
    //return move(argv[1], argv[2]);  // Implementation of the move function is platform dependent
                    // and beyond the scope of this article, so it is left out.
}  