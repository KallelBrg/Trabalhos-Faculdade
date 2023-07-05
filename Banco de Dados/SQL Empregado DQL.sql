select *
from Empregado
where dept = 5 and sexo = 'f' and salario < 2500

select nome, salario
from Empregado

select nome, salario
from Empregado
where dept = 2

select nome
from Gerenciou, Empregado
where Gerenciou.num_dept = 1 and Gerenciou.cpf_ger = Empregado.cpf

select cpf_gerente
from Departamento

select Empregado.cpf
from Empregado
where Empregado.cpf NOT IN (select cpf_ger from Gerenciou)

select Empregado.cpf
from Empregado
where salario > 3000 or Empregado.cpf IN (select cpf_ger from Gerenciou)

select Empregado.nome, Empregado.salario
from Empregado, Departamento
where Empregado.dept = Departamento.numero and Departamento.nome = 'Ensino'

select Empregado.nome
from Empregado, Trabalha_Para
where Empregado.cpf = Trabalha_Para.empregado and Trabalha_Para.projeto = 1

select Empregado.cpf
from Empregado
where Empregado.dept = 5

select Empregado.nome
from Empregado
where Empregado.cpf_supervisor = 333333

select Empregado.nome
from Empregado
where Empregado.cpf NOT IN (select empregado from Trabalha_Para)

select Empregado.cpf
from Empregado
where Empregado.cpf IN (select empregado from Trabalha_Para)

select Empregado.cpf
from Empregado
where Empregado.cpf IN (select cpf_gerente from Departamento) or Empregado.cpf NOT IN (select empregado from Trabalha_Para) 

select Dept, SUM(salario) 
from Empregado
GROUP BY Dept

select avg(salario)
from Empregado
GROUP BY dept
HAVING COUNT(*) > 5

select dept, max(salario)
from Empregado
where sexo = 'f'
GROUP BY dept
HAVING COUNT(dept) > 5
