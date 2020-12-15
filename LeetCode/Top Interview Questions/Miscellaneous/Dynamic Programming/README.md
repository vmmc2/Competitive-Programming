# Explicação para algumas questões.

## Min Cost Climbing Stairs.
* Primeiramente, a gente tem o ```vector<int> costs``` , com tamanho "n".
* Vamos dar um push_back() de "0" nesse vector. Esse novo elemento adicionado vai nos ajudar na montagem da nossa relação de recorrência da DP.
* Criamos um ```vector<int> dp(n + 1, 0)```. Onde dp[i] (0 <= i <= n) guarda o menor custo para chegar naquele degrau. Perceba que dp[0] = dp[1] = 0, pois o nosso primeiro passo, seja ele uma passo simples ou um passo duplo, não tem custo.
* Já para calcular dp[i] (2 <= i <= n), fazemos a seguinte recorrência: ```dp[i] = min(dp[i - 1] + costs[i - 1], dp[i - 2] + costs[i - 2])```
* ```dp[i - 1] + costs[i - 1] == (custo minimo para chegar naquele degrau n - 1) + (custo específico do degrau n - 1 que está sendo usado)```
* ```dp[i - 2] + costs[i - 2] == (custo minimo para chegar naquele degrau n - 2) + (custo específico do degrau n - 2 que está sendo usado)```
