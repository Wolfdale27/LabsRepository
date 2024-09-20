#include "labs_executor.hpp"
#include <memory>

int main() {
    std::unique_ptr<LabsExecutor> ptr_exe = std::make_unique<LabsExecutor>();//:^))))
    repeat: ptr_exe->Execute();

    std::string res = "";
    std::cout << "Что-нибудь еще посчитать?(Y/N): ";
    std::cin >> res;
    if(res=="Y" || res=="yes" || res=="y") goto repeat;

    return 0;
}