import os

entrada = ['10',
           '20',
           '40',
           '80',
           '100',
           '200',
           '400',
           '800',
           '1600',
           '3200',
           '6400',
           '12800',
           '25800',
           '51200',
           '102400',
           '204800',
           '409600',
           '819200',
           '1638400',
           '3276800'
           ]
ordem = ['norm',
         'inver',
         'aleat']

for i in range(0, len(ordem)):
    #os.system("cd "+ordem[i]+"")
    #for j in range (0, 2):
    #    os.system("./gera "+entrada[j]+" "+ordem[i]+" >entrada_"+ordem[i]+""+entrada[j]+".txt")
    os.chdir("/home/shiro/Documents/PAA_2/1_gera_string/norm")
    os.system("./gera 10 norm >entrada.txt")
