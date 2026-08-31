import { test, expect } from '@playwright/test';

test.describe('QS Acadêmico — Testes do Sistema de Notas', () => {
  test.beforeEach(async ({ page }) => {
    await page.goto('/');
  });

  // ========== GRUPO 1: Cadastro de Alunos ==========

  test.describe('Cadastro de Alunos', () => {

    test('deve cadastrar um aluno com dados válidos', async ({ page }) => {
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');
      await page.getByLabel('Nome do Aluno').fill('João Silva');
      await page.getByLabel('Nota 1').fill('7');
      await page.getByLabel('Nota 2').fill('8');
      await page.getByLabel('Nota 3').fill('6');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      // Verificar que o aluno aparece na tabela
      const linhas = page.locator('#tabela-alunos tbody tr');
      const linhaJoao = linhas.filter({ hasText: 'João Silva' });

      await expect(linhas).toHaveCount(1);
      await expect(linhaJoao).toHaveCount(1);
    });

    test('deve exibir mensagem de sucesso após cadastro', async ({ page }) => {
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');
      await page.getByLabel('Nome do Aluno').fill('Ana Costa');
      await page.getByLabel('Nota 1').fill('9');
      await page.getByLabel('Nota 2').fill('8');
      await page.getByLabel('Nota 3').fill('10');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      await expect(page.locator('#mensagem')).toContainText('cadastrado com sucesso');
    });

    test('não deve cadastrar aluno sem nome', async ({ page }) => {
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');
      await page.getByLabel('Nota 1').fill('7');
      await page.getByLabel('Nota 2').fill('8');
      await page.getByLabel('Nota 3').fill('6');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      // A tabela deve continuar sem dados reais
      await expect(page.locator('#tabela-alunos tbody td.texto-central')).toBeVisible();
    });

    test('Teste de validação de notas', async ({ page }) => {
      /*Verificar que o sistema rejeita notas fora do intervalo 0–10 (por exemplo, nota = 11 ou nota = -1).*/
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');
      await page.getByLabel('Nota 1').fill('11');
      await page.getByLabel('Nota 2').fill('-1');
      await page.getByLabel('Nota 3').fill('12');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      // A tabela deve continuar sem dados reais
      await expect(page.locator('#tabela-alunos tbody td.texto-central')).toBeVisible();
    });

    test('Teste de busca por nome', async ({ page }) => {
      /*Cadastrar dois alunos e verificar que o filtro de busca exibe apenas o aluno correspondente ao termo digitado.*/
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');
      await page.getByLabel('Nome do Aluno').fill('Bruno Wai Lu');
      await page.getByLabel('Nota 1').fill('10');
      await page.getByLabel('Nota 2').fill('10');
      await page.getByLabel('Nota 3').fill('10');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      await page.getByLabel('Nome do Aluno').fill('Thamiris Ferreira');
      await page.getByLabel('Nota 1').fill('10');
      await page.getByLabel('Nota 2').fill('10');
      await page.getByLabel('Nota 3').fill('10');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      await page.getByRole('textbox', { name: 'Buscar por nome' }).fill('Bruno Wai Lu');
      // Verificar que o aluno aparece na tabela
      const linhas = page.locator('#tabela-alunos tbody tr');
      const linhaFiltradas = linhas.filter({ hasText: 'Bruno Wai Lu' });

      await expect(linhas).toHaveCount(1);
      await expect(linhaFiltradas).toHaveCount(1);
    });

    test('Teste de exclusão', async ({ page }) => {
      /*Cadastrar um aluno, excluí-lo e verificar que a tabela ficou vazia novamente.*/
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');
      await page.getByLabel('Nome do Aluno').fill('Bruno Wai Lu');
      await page.getByLabel('Nota 1').fill('10');
      await page.getByLabel('Nota 2').fill('10');
      await page.getByLabel('Nota 3').fill('10');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      await page.getByRole('button', { name: 'Excluir Bruno Wai Lu' }).click();
      // A tabela deve continuar sem dados reais
      await expect(page.locator('#tabela-alunos tbody td.texto-central')).toBeVisible();
    });

  });

  // ========== GRUPO 2: Cálculo de Média ==========

  test.describe('Cálculo de Média', () => {

    test('deve calcular a média aritmética das três notas', async ({ page }) => {
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');
      await page.getByLabel('Nome do Aluno').fill('Pedro Santos');
      await page.getByLabel('Nota 1').fill('8');
      await page.getByLabel('Nota 2').fill('6');
      await page.getByLabel('Nota 3').fill('10');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      // Média esperada: (8 + 6 + 10) / 3 = 8.00
      const celulaMedia = page.locator('#tabela-alunos tbody tr').first().locator('td').nth(4);
      await expect(celulaMedia).toHaveText('8.00');
    });

    test('Teste de estatísticas', async ({ page }) => {
        await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');

        // ---------- ALUNO 1 (APROVADO) ----------
        await page.getByLabel('Nome do Aluno').fill('Aluno Aprovado');
        await page.locator('#nota1').fill('8');
        await page.locator('#nota2').fill('9');
        await page.locator('#nota3').fill('7');
        await page.getByRole('button', { name: 'Cadastrar' }).click();

        // ---------- ALUNO 2 (RECUPERAÇÃO) ----------
        await page.getByLabel('Nome do Aluno').fill('Aluno Recuperacao');
        await page.locator('#nota1').fill('5');
        await page.locator('#nota2').fill('6');
        await page.locator('#nota3').fill('5');
        await page.getByRole('button', { name: 'Cadastrar' }).click();

        // ---------- ALUNO 3 (REPROVADO) ----------
        await page.getByLabel('Nome do Aluno').fill('Aluno Reprovado');
        await page.locator('#nota1').fill('2');
        await page.locator('#nota2').fill('3');
        await page.locator('#nota3').fill('4');
        await page.getByRole('button', { name: 'Cadastrar' }).click();

        // ---------- VERIFICAÇÕES ----------
        await expect(page.locator('#stat-total')).toHaveText('3');
        await expect(page.locator('#stat-aprovados')).toHaveText('1');
        await expect(page.locator('#stat-recuperacao')).toHaveText('1');
        await expect(page.locator('#stat-reprovados')).toHaveText('1');
    });

    test('Teste de situação — Aprovado', async ({ page }) => {
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');

      await page.getByLabel('Nome do Aluno').fill('Aluno Aprovado');
      await page.locator('#nota1').fill('8');
      await page.locator('#nota2').fill('7');
      await page.locator('#nota3').fill('9');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      await expect(page.locator('#tabela-alunos tbody tr').last()).toContainText('Aprovado');
    });

    test('Teste de situação — Reprovado', async ({ page }) => {
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');

      await page.getByLabel('Nome do Aluno').fill('Aluno Reprovado');
      await page.locator('#nota1').fill('2');
      await page.locator('#nota2').fill('3');
      await page.locator('#nota3').fill('4');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      await expect(page.locator('#tabela-alunos tbody tr').last()).toContainText('Reprovado');
    });

    test('Teste de múltiplos cadastros', async ({ page }) => {
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');

      // Aluno 1
      await page.getByLabel('Nome do Aluno').fill('Aluno 1');
      await page.locator('#nota1').fill('7');
      await page.locator('#nota2').fill('7');
      await page.locator('#nota3').fill('7');
      await page.getByRole('button', { name: 'Cadastrar' }).click();

      // Aluno 2
      await page.getByLabel('Nome do Aluno').fill('Aluno 2');
      await page.locator('#nota1').fill('5');
      await page.locator('#nota2').fill('5');
      await page.locator('#nota3').fill('5');
      await page.getByRole('button', { name: 'Cadastrar' }).click();

      // Aluno 3
      await page.getByLabel('Nome do Aluno').fill('Aluno 3');
      await page.locator('#nota1').fill('3');
      await page.locator('#nota2').fill('3');
      await page.locator('#nota3').fill('3');
      await page.getByRole('button', { name: 'Cadastrar' }).click();

      await expect(page.locator('#tabela-alunos tbody tr')).toHaveCount(3);
    });

    test('Teste de situação — Recuperação', async ({ page }) => {
      await page.goto('https://brunowl-dev.github.io/02-TesteAutomatizado/');

      await page.getByLabel('Nome do Aluno').fill('Aluno Recuperacao');
      await page.locator('#nota1').fill('5');
      await page.locator('#nota2').fill('6');
      await page.locator('#nota3').fill('5');

      await page.getByRole('button', { name: 'Cadastrar' }).click();

      await expect(page.locator('#tabela-alunos tbody tr').last()).toContainText('Recuperação');
    });

  });
});