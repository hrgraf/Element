
#if HAVE_PYTHON
#include "controllers/ScriptingController.h"

#include <pybind11/embed.h>
namespace py = pybind11;

PYBIND11_EMBEDDED_MODULE(element, module) {
    module.def("add", [](int i, int j) -> int {
        return i + j;
    });
}

namespace Element {

struct PythonTest
{
    void run()
    {
        py::scoped_interpreter guard{};
        try {
            py::exec(R"(
                import element
                print(element.add(4, 5))
            )");
        }  catch (std::exception& e) {
            std::cout << e.what();
        }
    }
};

ScriptingController::ScriptingController() {}
ScriptingController::~ScriptingController() {}

void ScriptingController::activate()
{
    PythonTest().run();
}

void ScriptingController::deactivate()
{

}

}
#endif