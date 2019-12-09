import React from 'react';
import Persons from '../components/Persons/Persons'
import Cockpit from '../components/Cockpit/Cockpit';
import WithClass from '../hoc/WithClass';
import classes from './App.css';

class App extends React.Component {
  constructor(props) {
    super(props);
    console.log('[App.js] constructor');
  }

  state = {
    persons: [
      { id: 1, name: 'Max', age: 28 },
      { id: 2, name: 'Manu', age: 29 },
      { id: 3, name: 'Stephanie', age: 26 },
    ],
    otherState: 'some other value',
    showPersons: false,
    showCockpit: true,
  };

  static getDerivedStateFromProps(props, state) {
    console.log('[App.js] getDerivedStateFromProps', props);
    return state;
  }

  componentDidMount() {
    console.log('[App.js] componentDidMount');
  }

  shouldComponentUpdate(nextProps, nextState, nextContext) {
    console.log('[App.js] shouldComponentUpdate');
    return true; // true 와 false 로 업데이트를 진행, 블락 시킬 수 있음.
  }

  componentDidUpdate(prevProps, prevState, snapshot) {
    console.log('[App.js] componentDidUpdate');
  }

  deletePersonHandler = (personIndex) => {
    // const persons = this.state.persons; Array 는 reference type 이기 때문에 바로 조작하는 것은 위험
    // const persons = this.state.persons.slice(); 한 번 복사해서 사용
    const persons = [...this.state.persons];
    persons.splice(personIndex, 1);
    this.setState({
      persons: persons,
    });
  };

  nameChangeHandler = (event, id) => {
    const personIndex = this.state.persons.findIndex(p => {
      return p.id === id;
    });

    const person = { ...this.state.persons[personIndex] };
    // const person = Object.assign({}, this.state.persons[personIndex]);

    person.name = event.target.value;

    const persons = [...this.state.persons];
    persons[personIndex] = person;

    this.setState({
      persons: persons,
    });
  };

  togglePersonsHandler = () => {
    const doesShow = this.state.showPersons;
    this.setState({
      showPersons: !doesShow,
    });
  };

  render() {
    console.log('[App.js] render');
    let persons = null;

    if (this.state.showPersons) {
      persons = (
        <div>
          <Persons
            persons={this.state.persons}
            clikced={this.deletePersonHandler}
            changed={this.nameChangeHandler}
          />
        </div>
      );
    }

    return (
      <WithClass classes={classes.App}>
        <button
          onClick={() => {
            this.setState({showCockpit: false})
          }}
        >
          Remove Cockpit
        </button>
        {this.state.showCockpit &&
          <Cockpit
            showPersons={this.state.showPersons}
            personsLength={this.state.persons.length}
            clicked={this.togglePersonsHandler}
            title={this.props.appTitle}
          />
        }
        {persons}
      </WithClass>
    );
    // return React.createElement('div', {className: 'App'}, React.createElement('h1', 'Hi~~'...
  }
}

export default App;
