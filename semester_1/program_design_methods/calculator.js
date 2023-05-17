

/**
 * akm peny = akumulasi penyusutan
 * 
 * Features:
 *  1.  Profit & Loss Report
 *      attributes:
 *        - total_sales, sales_return, sales_disc, net_sales
 *        - beginning_inventory, purchase_cost, purchase_shipment_cost, purchase_return, purchase_disc, ending_inventory, hpp
 *        - hpp, production_expense, depreciation_of_production_expense, net_profit
 * 
 *      total_sales - sales_return  - sales_disc  = net_sales
 *      117_500_000 - 5_000_000     - 2_000_000   = 110_500_000
 * 
 *      Cost of Good Sold (COGS/HPP)
 *      beginning_inventory + purchase_cost + purchase_shipment_cost  - purchase_return - purchase_disc - ending_inventory  = HPP
 *      15_000_000          + 31_000_000    + 1_000_000               - 300_000         - 200_000       - 12_000_000        = 34_500_000
 * 
 *      Net Profit
 *      net_sales   - HPP         - production_expense(incl. equipment,electricity,water) = net_profit
 *      110_500_000 - 34_500_000  - 11_300_000                                            = 64_700_000
 * 
 *  2.  Statement of Changes in Equity (laporan perubahan ekuitas)
 *      beginning_capital + net_profit - prive      = statement_of_changes_in_equity
 *      90_000_000        + 64_700_000 - 5_000_000  = 149_700_000
 * 
 *  3.  Trial Balance (Neraca saldo)
 *      Cash      + Receivables + Supplies  + ending_inventory  + prepaid_insurance + (equipment - depreciation)  + (vehicles - depreciation) = trial_balance
 *      4_700_000 + 6_500_000   + 2_000_000 + 12_000_000        + 12_000_000        + 4_500_000                   + 120_500_000               = 162_200_000
 */

// const HPP = 15_000_000 + 31_000_000 + 1_000_000 - 300_000 - 200_000 - 12_000_000;
// const NET_PROFIT = 110_500_000 - 34_500_000  - 11_300_000;
// const statement_of_changes_in_equity = 90_000_000 + 64_700_000 - 5_000_000;
// const trial_balance = 4_700_000 + 6_500_000 + 2_000_000 + 12_000_000 + 12_000_000 + 4_500_000 + 120_500_000;

// console.log('net_sales', 117_500_000 - 5_000_000 - 2_000_000);
// console.log('COGS/HPP', HPP);
// console.log('NET_PROFIT', NET_PROFIT);
// console.log('statement_of_changes_in_equity', statement_of_changes_in_equity);
// console.log('trial_balance', trial_balance);

import prompt from 'prompt';

class Input {
  constructor() {}

  async getInputFromUser(key) {
    prompt.start();

    const schema = {
      properties: {
        [key]: {
          description: '',
          message: ''
        },
      }
    }

    const promptResult = await prompt.get(schema);

    return promptResult[key];
  }
}

class Report {
  constructor() {
    this._entries = [];
    this._input = new Input();
  }

  setEntry(key, val) {
    let entryIndex = Object.keys(this._entries).findIndex(el => el == key);

    if (entryIndex < 0) {
      entryIndex = this._entries.length;
    }

    this._entries[entryIndex] = { [key]: val };
  }
}

class ProfitLossReport extends Report {
  // total_sales, sales_return, sales_disc, net_sales
  // beginning_inventory, purchase_cost, purchase_shipment_cost, purchase_return, purchase_disc, ending_inventory, hpp
  // hpp, production_expense, depreciation_of_production_expense, net_profit
  constructor() {
    super();

    this.allowedAttributes = [
      'TotalSales',
      'TotalSales',
      'SalesDiscount',
      'setNetSales',
    ];
  }

  async inputTotalSales() {
    const key = 'TotalSales';
    this.setEntry(key, await this._input.getInputFromUser(key));
  }

  async inputSalesReturn() {
    const key = 'SalesReturn';
    this.setEntry(key, await this._input.getInputFromUser(key));
  }

  async inputSalesDiscount() {
    const key = 'SalesDiscount';
    this.setEntry(key, await this._input.getInputFromUser(key));
  }

  async inputNetSales() {
    const key = 'NetSales';
    this.setEntry(key, await this._input.getInputFromUser(key));
  }

  get entries() {
    return this._entries;
  }
}

class App {
  constructor() {
    this._options = {
      0: 'exit',
      1: 'Profit & Loss Report',
      10: 'Print All Entries'
    }
  }

  async perform() {
    let continueLoop = 1;

    while (continueLoop) {
      console.log('Options:');

      for (let key in this._options) {
        console.log(key, this._options[key]);
      }

      const inputClass      = new Input();
      const optionSelected  = await inputClass.getInputFromUser('select option');

      if (optionSelected == '0') {
        continueLoop = 0;
      }
    }

    console.log('Good bye.');
  }
}

// const profitAndLossReport = new ProfitLossReport();
// profitAndLossReport.inputTotalSales();
// console.log(profitAndLossReport.entries);
const app = new App();
app.perform();


