#include <iostream>
#include <glm/glm.hpp>

#include "EulerOp.hpp"
#include "Sweep.hpp"
#include "Draw.hpp"

int displayEulerOp = 1; // 1: display each Euler Operation, 0: otherwise

Solid * cube(){
    std::cout << "construct cube:" << std::endl;
    Solid *solid;

    Vertex *v[9];
    solid = EulerOp::mvfs(v[0], glm::vec3(0.7, 1.1, 0.0));
    Face *topFace = solid->Sfaces;
    Loop *top = topFace->Floops;
    EulerOp::mev(v[0], v[1], glm::vec3(-0.4, 1.6, 0.0), top);
    EulerOp::mev(v[1], v[2], glm::vec3(-1.2, -0.5, 0.0), top);
    EulerOp::mev(v[2], v[3], glm::vec3(0, -1.5, 0.0), top);
    EulerOp::mev(v[3], v[4], glm::vec3(1.0, 0.8, 0.0), top);
    EulerOp::mef(v[4], v[0], top);
    //HalfEdge *Hedg = EulerOp::mev(v[0], v[5], glm::vec3(0.5, 0, 0.0), top);
    //Edge *edg = Hedg->HEedge;
    //Loop *inner = EulerOp::kemr(edg, top);
    //EulerOp::mev(v[5], v[6], glm::vec3(0, -0.5, 0.0), top);
    //EulerOp::mev(v[6], v[7], glm::vec3(-0.5, 0, 0.0), top);
    //EulerOp::mef(v[7], v[5], top);
    
    

    solid = Sweep::sweep(topFace, glm::vec3(0.0, 0.0, 1.0), 1.5);
    
    return solid;
}

int main(int argc, char **argv){
    Solid *solid;
    solid = cube();
    // shading
    Draw::init();
    Draw::draw(solid);
    Draw::end();

    return 0;
}