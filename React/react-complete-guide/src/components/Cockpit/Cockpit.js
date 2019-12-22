import React, { useEffect, useRef } from 'react';
import classes from './Cockpit.css';
import AuthContext from '../../context/auth-context';

const Cockpit = (props) => {
  const toggleBtnRef = useRef(null);

  useEffect(() => {
    console.log('[Cockpit.js] useEffect');
    // Http request...
    // setTimeout(() => {
    //   alert('Saved data to cloud!');
    // }, 1000);
    toggleBtnRef.current.click();
    return () => {
      console.log('[Cockpit.js] cleanup work in useEffect');
    }; // empty array 이므로 마지막 사라질 때 한 번 호출
  }, []);

  useEffect(() => {
    console.log('[Cockpit.js] 2nd useEffect');
    return () => {
      console.log('[Cockpit.js] cleanup work in 2nd useEffect');
    }; // update 될 때마다 호출
  });

  const assignedClasses = [];
  let btnClass = '';
  if (props.showPersons) {
    btnClass = classes.Red;
  }

  if (props.personsLength <= 2) {
    assignedClasses.push(classes.red);
  }
  if (props.personsLength <= 1) {
    assignedClasses.push(classes.bold);
  }

  return (
    <div className={classes.Cockpit}>
      <h1>{props.title}</h1>
      <p className={assignedClasses.join(' ')}>This is really working!</p>
      <button ref={toggleBtnRef} className={btnClass} onClick={props.clicked}>
        Toggle Persons
      </button>
      <AuthContext.Consumer>
        {(context) => <button onClick={context.login}>Log in</button>}
      </AuthContext.Consumer>
    </div>
  );
};

export default React.memo(Cockpit);
// React.memo 는 memoization 을 해놓고 내부가 바뀌지 않았으면 해당 스냅샷을 넘기고 바꼈으면 re-rendering
// 내부가 바뀌지 않았는데 부모의 re-rendering 으로 인해 매번 같이 리렌더링 되는 것을 방지하여 performance optimization 을 한다.
// class 형식에서 shouldComponentUpdate 의 이전과 비교하여 업데이트 하는 방식과 같은 것이다.
// 하지만 이것을 작성하는 것도 성능 걸림돌이 될 수 있다. 확실하게 부모에 의해 매번 리렌더링 된다고 생각하면 빼는 것도 좋다.
