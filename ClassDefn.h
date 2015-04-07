//
//  ClassDefn.h
//  mojito
//
//  Created by Javed Shaik on 20/02/15.
//
//
#ifndef UMOD_AST_CLASSDEFN_H_
#define UMOD_AST_CLASSDEFN_H_

namespace umod {
    namespace ast{
        class classdefn: public ast::node
        {
            /*
             this.restriction = ;
             this.isFinal = false;
             this.isEncapsulated = false;
             this.isPartial = false;
             this.isOperator = false;
             this.isExpandable = false;
             this.isPure = false;
             this.isImpure = false;
             // class_specifier
             this.shortSpecifier = undefined;
             this.isExtends = false;
             this.ident = udefined;
             this.classModification = udefined;
             this.stringComment = undefined;
             //composition 
             this.importClauseList = [];
             this.extendsClauseList = [];
             this.classDefinitionList = [];
             this.componentClauseList = [];
             //equations 
             this.intialEquationList = [];
             this.statementList = [];
             this.external = undefiend;
             this.annotation = undefined;
             //optional element declartions;
             this.isRedeclare = false;
             this.isFinal = false;
             this.isInner = false;
             this.isOuter = false;
             this.isReplacable = false;
             //optional constraining clause for element_replacable
             this.constrainingClause = undefined;
             */
        };
    }
}

#endif /* UMOD_AST_CLASSDEFN_H_ */
