#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
        return (std::cerr << "Error: there should be at least be two arguments." << std::endl, 1);
    try
    {
        PmergeMe amigo(av);
        amigo.printbeforelist();
        // amigo.sortlist();
        amigo.sortvector();
        amigo.afterlist();

        // amigo.printvector();
        // amigo.printlist();

        // arg = 3 2 4 1 15 14 5 6 12 10
        // primera vuelta
        // Par 1: (2, 3)
        // Par 2: (1, 4)
        // Par 3: (14, 15)
        // Par 4: (5, 6)
        // Par 5: (10, 12)
    
        //segunda vuelta
        // L = [2,1,14,5,10] a1, a2, a3, a4, a5 // los menores de cada par
        // H = [3,4,15,6,12] b1, b2, b3, b4, b5 // los mayores de cada par
        // para cualquier a siempre son mas pequeños que su b correspondiente
        // (3,4), (6,15), + 12 (sobrante) == b1, b2, b4, b3 + b5
        // L2 = [3,6]           // menores de cada par
        // H2 = [4,15,12]       // mayores de cada par
        // L3 = [4]     // menores
        // H3 = [15,12] // mayores
        // L4 = [12]
        // H4 = [15]
        // fin de la recursividad nos quedamos con esa ultima pareja e insertamos en ella el resto de numeros mas pequeños en orden jacobstal
        // Regla: Para n pequeños, la secuencia de inserción (índices) es:
        // n = 5 → secuencia Jacobsthal de índices = 1,3,2,5,4
        // Donde los índices corresponden a:

        // L = [2,1,14,5,10]
        // Índices: 1=2, 2=1, 3=14, 4=5, 5=10

        // Entonces el orden de inserción de los pequeños será:

        // 14 (índice 3), 2 (índice 1), 1 (índice 2), 10 (índice 5), 5 (índice 4)

        // Nota: esto puede variar según la versión exacta de Jacobsthal usada, pero la idea es insertar primero los aᵢ que “no tendrán números menores posteriores”, luego los que podrían estar entre ellos.

        // 4️⃣ Insertamos los pequeños en la main chain

        // Main chain H ordenada hasta ahora:

        // [3,4,6,12,15]  (supongamos que ya aplicamos la recursión sobre H)

        // Orden de inserción Jacobsthal:
        // 14 → inserción entre 12 y 15 → [3,4,6,12,14,15]
        // 2 → inserción al inicio → [2,3,4,6,12,14,15]
        // 1 → inserción al inicio → [1,2,3,4,6,12,14,15]
        // 10 → inserción entre 6 y 12 → [1,2,3,4,6,10,12,14,15]
        // 5 → inserción entre 4 y 6 → [1,2,3,4,5,6,10,12,14,15]
        // 5️⃣ Resultado final
        // [1, 2, 3, 4, 5, 6, 10, 12, 14, 15]

        // ✅ Main chain completamente ordenada
        // ✅ Cada pequeño se insertó después de que todos los números menores posibles ya estaban presentes
        // ✅ No hubo ningún problema como el caso hipotético de “6 y 8”

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
}    