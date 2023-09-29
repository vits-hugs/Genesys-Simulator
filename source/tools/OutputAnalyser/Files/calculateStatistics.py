import os
import statistics

def calcular_estatisticas(arquivo):
    with open(arquivo, 'r') as file:
        for _ in range(2):
            next(file)

        numeros = [float(line.strip()) for line in file]

    # Calcula a média, desvio padrão, máximo e mínimo
    media = statistics.mean(numeros)
    desvio_padrao = statistics.stdev(numeros)
    maximo = max(numeros)
    minimo = min(numeros)
    variancia = statistics.variance(numeros)
    moda = statistics.mode(numeros)

    return media, desvio_padrao, maximo, minimo, variancia, moda

diretorio_atual = os.getcwd()
nome_arquivo = 'TriangularDist.txt'

caminho_arquivo = os.path.join(diretorio_atual, nome_arquivo)

media, desvio_padrao, maximo, minimo, variancia, moda = calcular_estatisticas(caminho_arquivo)
rate = media / variancia
shape = round(media * rate)
alpha = media * ((media * (1-media) / variancia) - 1)
beta = (1 - media) * ((media * (1-media) / variancia) - 1)


print(f'Média: {media}')
print(f'Desvio Padrão: {desvio_padrao}')
print(f'Máximo: {maximo}')
print(f'Mínimo: {minimo}')
print(f'Moda: {moda}')
print(f'Shape: {shape}')
print(f'Rate: {rate}')
print(f'Alpha: {alpha}')
print(f'Beta: {beta}')
