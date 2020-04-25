import React, { Component } from 'react';
import { Route, NavLink, Switch, Redirect } from 'react-router-dom';

import './Blog.css';
import Posts from './Posts/Posts';
import asyncComponent from '../../hoc/asyncComponent';
// import NewPost from './NewPost/NewPost';

const AsyncNewPost = asyncComponent(() => {
  return import('./NewPost/NewPost');
});

class Blog extends Component {
  state = {
    auth: true,
  }

  render () {
    return (
      <div className="Blog">
        <header>
          <nav>
            <ul>
              <li><NavLink
                to="/posts"
                exact
                activeClassName="my-active"
                activeStyle={{
                  color: '#fa923f',
                  textDecoration: 'underline'
                }}
              >
                Home
              </NavLink></li>
              <li><NavLink to={{
                pathname: '/new-post',
                hash: '#submit', // id 가 submit 인 곳으로 이동
                search: '?quick-submit=true' // query param
              }}>New Post</NavLink></li>
            </ul>
          </nav>
        </header>
        {/*<Route path="/" exact render={() => <h1>Home</h1>} />*/}
        {/*<Route path="/" render={() => <h1>Home 2</h1>} />*/}
        <Switch> {/* 하나 해당되면 거기서 멈추고 더 이상 탐색하지 않음. */}
          {this.state.auth ? <Route path="/new-post" component={AsyncNewPost} /> : null}
          <Route path="/posts" component={Posts} />
          <Route render={() => <h1>Not found</h1>} />
          {/*<Redirect from="/" to="/posts" />*/}
          {/*<Route path="/" component={Posts} />*/}
        </Switch>
      </div>
    );
  }
}

export default Blog;
