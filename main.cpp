#include <glm/glm.hpp>
#include <Eigen/Dense>

#include <GL/glew.h>   
#include <math.h>

        struct Vertex {
            double x;
            double y;
            double z;
        }

struct Matrix {
    double r11;
    double r12;
    double r13;

    double r21;
    double r22;
    double r23;

    double r31;
    double r32;
    double r33;

}

struct RigidBody {
    // константные значения
    double mass;
    glm::mat3 Ibody;
    glm::mat3 Ibodyinv;    

    //переменные значения
    glm::vec3 x;
    glm::mat3 R;
    glm::vec3 P;        
    glm::vec3 L;
    //вспомогательные величины 

    glm::mat3 Iinv; 
    glm::vec3 v;
    glm::vec3 omega;
    glm::vec3 force; // возможно не нужен 
    glm::vec3 torque; // возможно не нужен 

    unsigned int VAO_id;
    unsigned int T;

}


void renewalForce (const std::vector<Vertex>& r, const std::vector<Vertex>& x, std::vector<Vertex>& F, std::vector<Vertex>& t, int numberPoints, int numberObjects, double sigma, double epsilont) {
    
    for (int q = 0; q < numberObjects; q++) {

        for (int w = q + 1; w < numberObjects; w++){

            for (int t = 0; t < numberPoints; t ++){
                
                for (int l = 0; l < numberPoints; l ++) {
                    int idx_1 = q * numberPoints + t;
                    int idx_2 = w * numberPoints + l;

                    glm::vec3 r_1 (r [idx_1].x, r [idx_1].y, r [idx_1].z); 
                    glm::vec3 r_2 (r [idx_2].x, r [idx_2].y, r [idx_2].z);

                    glm::vec3 F_1 (0.0f);
    

                    double length = glm::distance (r_1, r_2);

                    double attitude = sigma / length ;

                    if (length < 2.5 * sigma) {
                        f_mag = ( 4 * epsilont / length ) * 12 * pow (attitude, 12.0f) - 6 * pow (attitude, 6.0f); // сила Леннарда-Джонса 

                        glm::vec3 direction =  glm::normalize (r_2 - r_1 );

                        F_1 = direction * f_mag;

                    }



                    F[q].x += F_1[0];
                    F[q].y += F_1[1];
                    F[q].z += F_1[2];


                    F[w].x -= F_1[0];
                    F[w].y -= F_1[1];
                    F[w].z -= F_1[2];

                    t_vector = 

                    if (length < trigger){
                        

                        //возможно рассматривать сближение объектов  
                    }

                    //обновление момента импульса 
                }
            }

        }
    }
    
}




void globalStep (std::vector<RigidBody> Objects, double h ){
    
}


void VisibleObjects(const std::vector<RigidBody>& Objects, const glm::mat4& viewMatrix, const glm::mat4& projMatrix) {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderProgram);

    GLint projLoc = glGetUniformLocation(shaderProgram, "u_Projection");
    GLint viewLoc = glGetUniformLocation(shaderProgram, "u_View");
    GLint modelLoc = glGetUniformLocation(shaderProgram, "u_Model"); 

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projMatrix));


    for (size_t idx = 0; idx < Objects.size(); ++idx) {

        const RigidBody& obj = Objects[idx];

        glm::mat4 matrixModel(1.0f); 

        matrixModel[0][0] = obj.R[0][0]; matrixModel[0][1] = obj.R[0][1]; matrixModel[0][2] = obj.R[0][2];
        matrixModel[1][0] = obj.R[1][0]; matrixModel[1][1] = obj.R[1][1]; matrixModel[1][2] = obj.R[1][2];
        matrixModel[2][0] = obj.R[2][0]; matrixModel[2][1] = obj.R[2][1]; matrixModel[2][2] = obj.R[2][2];
        

        matrixModel[3][0] = obj.x[0]; 
        matrixModel[3][1] = obj.x[1];
        matrixModel[3][2] = obj.x[2]; 

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(matrixModel));


        glBindVertexArray(obj.VAO_id);


        glDrawElements(GL_TRIANGLES, obj.T * 3, GL_UNSIGNED_INT, 0);
    }

    glutSwapBuffers();
}






std::vector<Vertex> generateBumpySurface (int ridSize, ) {
    

}



int main () {

}