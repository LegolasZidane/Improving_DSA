import java.util.StringTokenizer;
class Spreadsheet {

int grid[][];
    
    public Spreadsheet(int rows) {
        grid = new int[rows][26];
    }
    
    public void setCell(String cell, int value) {

        int col = Integer.parseInt(cell.substring(1));
        grid[col - 1][cell.charAt(0)-'A'] = value;
        
    }
    
    public void resetCell(String cell) {

        int col = Integer.parseInt(cell.substring(1));
        grid[col - 1][cell.charAt(0)-'A'] = 0;
        
    }
    
    public int getValue(String formula) {

        StringTokenizer st = new StringTokenizer(formula, "=+");
        int col1, col2;
        String index1 = st.nextToken();
        String index2 = st.nextToken();
        int num1 = 0, num2 = 0;
        if( index1.charAt(0) < 65 )
            num1 = Integer.parseInt(index1);
        else
        {
            System.out.println(index1.charAt(0)+1);
            col1 = Integer.parseInt(index1.substring(1));
            num1 = grid[col1 - 1][index1.charAt(0)-'A'];
        }
        System.out.println(index2);
        if( !(index2.charAt(0) >= 'A') )
            num2 = Integer.parseInt(index2);
        else
        {
            col2 = Integer.parseInt(index2.substring(1));
            num2 = grid[col2 - 1][index2.charAt(0)-'A'];
        }
        System.out.println(num2);
        return (num1 + num2);
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */