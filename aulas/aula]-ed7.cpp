/*
    aula de Análise de Algoritmos:
        objetivo:
            estimar o tempo de execução de um algoritmo de forma analítica.

        a análise de algoritmos é a área que estuda como estmar teoricamente os recursos que um algoritmo precisará a fim de resolver um problema computacional

        ao se analisar um algoritmo, estamos geralmente preocupados com duas medidas
            tempo de execução
            memória
        Tempo e processamento:
            medir o tempo (em microssegundos) gasto por um algoritmo
        complexidade do algoritmo:
            Queremso analisar algoritmos:
                independentemente do computador onde ele for rodado

                em função do valor de N (a quantidade de dados)

            para evitar análise dependente de tempo, considera-se qu um algoritmo é subdividido, ao envés de milissegundos, em uma quantidade finita de passos
                um passo é uma instrução indivisível e de tempo constante, ou seja, indevendente de condiçóes de entradas e processamento.
            A quantidade de passos necessários ao comprimento de um algoritmo é denominada complexidade do algoritmo.

            ex.:
            int busca(int v[], int n, int x){
                int i;
                for (int i= 0;i<n;i++){
                    if(v[i] == x){
                        return i;
                    }
                }
                return -1;
            }

            consumo de tempo por linha no pior caso:
            . linha 2: tempo c2 (declaração de variável)
            . linha 3: tempo c3 (atribuições, acessos e comparação)
                no pior caso, essa linha é executada n+1 vezes
            . linha 4: tempo c4 (acessos e comparação)
                no pior caso, essa linha é executada n vezes
            . linha 5: tempo c5 (acesso e return)
            . linha 6: tempo c6 (return)

            o tempo de execução é menor ou igual a
                c2+ c3.(n+1)+c4.n+c5+c6

            cada ci não depende de n, devende apenas do computador
                leva um tempo constate

            sejam a: c

            soma de matrizes:
            sejam a e b duas matrizes quadradas de ordem n que devem ser somadas.

            void soma( int **a, int **b, int **c,int n){
                for(int i =0; i<n;i++){
                    for(int j=0;j<n;j++){
                        c[i][j] = a[i][j] + b[i][j]
                    }
                }
            }

            multiplicação de matrizes:

            void multi(int **a, int **b, int **c, int n){
                for(int i =0;i< n;i++){
                    for(int j=0;j<n;j++){
                        c[i][j] = 0;
                        for(int k= 0; k<n;k++){
                            c[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
            }

        Crecimento assintótico de funções
            notação O
                Gig-O

*/
