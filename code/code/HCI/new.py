import tkinter as tk

# Create the main window
window = tk.Tk()
window.title("Button Window")
window.geometry("400x300")
# window.attributes("-fullscreen", True)
# Create four buttons
window.configure(bg="lightblue")

button1 = tk.Button(window, text="Button 1")
button2 = tk.Button(window, text="Button 2")
button3 = tk.Button(window, text="Button 3")
button4 = tk.Button(window, text="Button 4")

# Pack the buttons into the window (you can use grid or place as well)
button1.pack()
button2.pack()
button3.pack()
button4.pack()


def display_input():
    input_text = entry.get()  # Get the text from the Entry widget
    label_output.config(text="You entered: " + input_text)  # Update the label

# Create a Label widget
label = tk.Label(window, text="Enter your name:")

# Create an Entry widget
entry = tk.Entry(window)

# Create a Button widget to trigger the display_input function
button = tk.Button(window, text="Submit", command=display_input)

# Create a Label widget to display the entered text
label_output = tk.Label(window, text="")

# Pack the widgets into the window
label.pack()
entry.pack()
button.pack()
label_output.pack()

# Start the main loop to display the window
window.mainloop()
