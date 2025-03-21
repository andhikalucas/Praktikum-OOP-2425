#include "Agent.hpp"
#include "SuperAgent.hpp"

int main(){
    SuperAgent agentX;
    Agent *apalah = &agentX;
    apalah->setID(1337);
    agentX.setID(9999);

    agentX.print();
    return 0;
}