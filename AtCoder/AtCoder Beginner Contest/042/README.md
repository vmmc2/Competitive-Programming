# Explicacao dos problemas dificeis do contest.

# Problema D
* Devemos ter em mente o seguinte: Dado um grid (M x N), a quantidade maneiras de irmos das coordenada (0,0) ate a coordenada (M-1,N-1) eh dada pela seguinte forma de combinacao:
```
(m - 1 + n - 1) C (n - 1) = (m + n - 2) C (n - 1) =          (m + n - 2)!        =       (m + n - 2)!
                                                    ---------------------------     ---------------------
                                                    (m+n-2 - (n-1))! * (n - 1)!      (m - 1)! * (n - 1)!
```
