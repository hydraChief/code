import tkinter as tk

window = tk.Tk()
window.title("HCI PRACTICAL")
window.geometry("450x400")
window.configure(bg='light blue')

def apply():
    input_text = Entry.get()
    output.config(text="You Entered: " + input_text)

label1 = tk.Label(window, text="Enter The DATA")
label1.grid(row=0, column=0, columnspan=2)  # Span two columns

Entry = tk.Entry(window)
Entry.grid(row=1, column=0, columnspan=2)  # Span two columns

button2 = tk.Button(window, text="Submit", command=apply)
button2.grid(row=2, column=0, columnspan=2)  # Span two columns

output = tk.Label(window, text="")
output.grid(row=3, column=0, columnspan=2)  # Span two columns

# Creating a grid of 4 buttons
button3 = tk.Button(window, text="Button 3", width=20)
button3.grid(row=4, column=0)

button4 = tk.Button(window, text="Button 4", width=20)
button4.grid(row=4, column=1)

button5 = tk.Button(window, text="Button 5", width=20)
button5.grid(row=5, column=0)

button6 = tk.Button(window, text="Button 6", width=20)
button6.grid(row=5, column=1)

window.mainloop()
