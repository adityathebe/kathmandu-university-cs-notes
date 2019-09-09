public class StackArray {

  private int[] stackElements;
  private int topIndex;
  private int maxSize;

  public StackArray(int maxSize) {
    this.maxSize = maxSize;
    this.stackElements = new int[maxSize];
    this.topIndex = -1;
  }

  public Boolean isFull() {
    return topIndex == maxSize - 1;
  }

  public Boolean isEmpty() {
    return topIndex == -1;
  }

  public void push(int element) {
    if (!isFull()) {
      topIndex += 1;
      stackElements[topIndex] = element;
    } else {
      System.out.println("Stack is full");
    }
  }

  public int pop() {
    if (!isEmpty()) {
      return stackElements[topIndex--];
    }
    System.out.println("Stack is empty");
    return -1;
  }

  public int peek() {
    if (!isEmpty()) {
      return stackElements[topIndex];
    }
    System.out.println("Stack is empty");
    return -1;
  }

  public static void main(String[] args) {
    StackArray stack = new StackArray(4);
    stack.push(5);
    stack.push(8);
    stack.push(2);
    stack.push(9);

    System.out.println("*********************Stack Array Implementation*********************");
    System.out.println(stack.isEmpty()); // false
    System.out.println(stack.isFull()); // true
    System.out.println(stack.peek()); // 9
    System.out.println(stack.pop()); // 9
    System.out.println(stack.peek()); // 2
  }
}