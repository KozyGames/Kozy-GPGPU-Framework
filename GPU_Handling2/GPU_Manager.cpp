#include "GPU_Manager.hpp"

namespace Kozy {

    GPU_Manager::~GPU_Manager() {
        gpuCaller.exec_unload_GPU();
    }

}