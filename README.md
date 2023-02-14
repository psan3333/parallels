# parallels
(time: секунды - везде в тексте)
For double:
1. Sum + initialization (GPU): 1.012548; time: 0.036696

2. Sum + initialization (CPU): -0.000779; time: 0.070967

For float:
1. Sum + initialization (GPU): 1.012548; time: 0.019097

2. Sum + initialization (CPU): -644531.875000; time: 0.075783

Таким образом можно увидеть, что точность double на GPU примерно такая же, как и для float.
Если говорить о CPU, то здесь можно увидеть колосальное различие в точности: для double в принципе самая высокая точность среди всех испытаний, а вот для float мы видим, что точность как раз таки наоборот самой низкой оказалась.

Вывод:
float и double на GPU имеют примерно одинаковую точность расчётов, хотя и уступают double на CPU. float CPU имеет самую низкую точность расчётов.

Время копирования с CPU на GPU:
delta time 'pragma acc data copy(new_sin[0:N])': 3.197533 - достаточно долго
