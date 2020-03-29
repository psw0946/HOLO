import Cmp from './base-component';
import * as Validation from '../util/validation';
import { autobind as Autobind } from '../decorators/autobind';
import { projectState } from '../state/project-state';

export class ProjectInput extends Cmp<HTMLDivElement, HTMLFormElement>{
    titleInputElement: HTMLInputElement;
    descriptionElement: HTMLInputElement;
    peopleInputElement: HTMLInputElement;

    constructor() {
        super('project-input', 'app', true, 'user-input');
        this.titleInputElement = this.element.querySelector('#title') as HTMLInputElement;
        this.descriptionElement = this.element.querySelector('#description') as HTMLInputElement;
        this.peopleInputElement = this.element.querySelector('#people') as HTMLInputElement;

        this.configure();
    }

    configure() {
        // bind(this) 를 안해주면 submitHandler 의 this 는 event 를 가리킨다.
        this.element.addEventListener('submit', this.submitHandler);
    }

    renderContent(): void {}

    private gatherUserInput(): [string, string, number] | void {
        const enteredTitle = this.titleInputElement.value;
        const enteredDescription = this.descriptionElement.value;
        const enteredPeople = this.peopleInputElement.value;

        const titleValidatable: Validation.Validatable = {
            value: enteredTitle,
            required: true
        };
        const descriptionValidatable: Validation.Validatable = {
            value: enteredDescription,
            required: true,
            minLength: 5
        };
        const peopleValidatable: Validation.Validatable = {
            value: enteredPeople,
            required: true,
            min: 1,
            max: 5
        };

        if (Validation.validate(titleValidatable) && Validation.validate(descriptionValidatable) && Validation.validate(peopleValidatable)) {
            return [enteredTitle, enteredDescription, +enteredPeople]
        } else {
            alert('Invalid input, please try again!');
            return;
        }
    }

    private clearInputs() {
        this.titleInputElement.value = '';
        this.descriptionElement.value = '';
        this.peopleInputElement.value = '';
    }

    @Autobind
    private submitHandler(event: Event) {
        event.preventDefault();
        const userInput = this.gatherUserInput();
        if (Array.isArray(userInput)) {
            const [title, description, people] = userInput;
            projectState.addProject(title, description, people);
            this.clearInputs();
        }
    }
}
