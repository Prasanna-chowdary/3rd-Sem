class Animal:
    def _init_(self, name):
        self.name = name

    def eat(self):
        print(f"{self.name} is eating.")

    def sleep(self):
        print(f"{self.name} is sleeping.")

class Dog(Animal):
    def _init_(self, name, breed):
        super()._init_(name)
        self.breed = breed

    def bark(self):
        print(f"{self.name} (a {self.breed}) barks: Woof! Woof!")

class Cat(Animal):
    def _init_(self, name, color):
        super()._init_(name)
        self.color = color

    def meow(self):
        print(f"{self.name} (a {self.color} cat) meows: Meow!")

class Bird(Animal):
    def _init_(self, name, species):
        super()._init_(name)
        self.species = species

    def fly(self):
        print(f"{self.name} (a {self.species}) is flying high!")

# Demonstrating inheritance
print("\n--- Inheritance Demonstration ---")
my_dog = Dog("Buddy", "Golden Retriever")
my_cat = Cat("Whiskers", "Tabby")
my_bird = Bird("Sky", "Parrot")

my_dog.eat()
my_dog.bark()
my_dog.sleep()

my_cat.eat()
my_cat.meow()
my_cat.sleep()

my_bird.eat()
my_bird.fly()
my_bird.sleep()
