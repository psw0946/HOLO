import React, { Component } from 'react';
import Person from './Person/Person';

class Persons extends Component {
  // static getDerivedStateFromProps(props, state) {
  //   console.log('[Persons.js] getDerivedStateFromProps');
  //   return state;
  // }

  // componentWillReceiveProps(nextProps, nextContext) {
  //   console.log('[Persons.js] componentWillReceiveProps', props);
  // }

  // shouldComponentUpdate(nextProps, nextState, nextContext) {
  //   console.log('[Persons.js] shouldComponentUpdate');
  //   return nextProps.persons !== this.props.persons;
  //   // cockpit 을 수정해도 app.js 가 영향을 받아 Persons 도 re-rendering 되는데, 그것을 막아줘서 performance optimization 한다.
  // }
  // PureComponent 를 위에서 상속받으면 shouldComponentUpdate 가 없어도 그 역할을 대신해줄 수 있다. (부모로부터 받은 props 를 현재 가지고 있는 것과 자동으로 비교해줌. 단, 얕은 복사 기준으로 비교)

  getSnapshotBeforeUpdate(prevProps, prevState) {
    console.log('[Persons.js] getSnapshotBeforeUpdate');
    return { message: 'Snapshot!' };
  }

  // componentWillUpdate(nextProps, nextState, nextContext) {
  // }

  componentDidUpdate(prevProps, prevState, snapshot) {
    console.log('[Persons.js] componentDidUpdate');
    console.log(snapshot);
  }

  componentWillUnmount() {
    console.log('[Persons.js] componentWillUnmount');
  }

  render() {
    console.log('[Person.js] rendering...');
    return this.props.persons.map((person, index) => {
      return <Person
        key={index}
        click={() => this.props.clicked(index)}
        name={person.name}
        age={person.age}
        changed={(event) => this.props.changed(event, person.id)}
        isAuth={this.props.isAuthenticated}
      />
    });
  }
}

export default Persons;
